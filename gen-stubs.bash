#!/bin/bash

filter_classifiers()
{
   sed 's/static//;s/__inline__//;s/^[\t ]*//'
}

ret_type_for()
{
   filter_classifiers <<<"$1" | sed 's/^const[\t ]*//' | grep -Eo '^(struct|unsigned)? *[a-zA-Z_]+[\t \*]*'
}

fun_name_for()
{
   filter_classifiers <<<"$1" | sed 's/struct//;s/const//;s/unsigned//;s/^[\t ]*//;s/[a-zA-Z_]\+[\t \*]*//' | grep -Eo '^[a-zA-Z_]+'
}

should_error()
{
   # stubs that should return error value
   grep -Fqs "$(cat << EOF
_malloc
snd_config_
EOF
)" <<<"$1"
}

return_for()
{
   ret="$(ret_type_for "$1" | xargs)"
   case "$ret" in
      *\*|snd_config_iterator_t)
         printf 'return NULL;'
         ;;
      void)
         printf ''
         ;;
      snd_pcm_sync_id_t|snd_htimestamp_t)
         printf 'return (%s){0};' "$ret"
         ;;
      'unsigned char'|int|'unsigned int'|long|'unsigned long'|size_t|ssize_t|pid_t|snd_*)
         if should_error "$2"; then
            printf 'return -1;'
         else
            printf 'return 0;'
         fi
         ;;
      *)
         printf 'unhandled return type: %s\n' "$ret" 1>&2
         exit 1
         ;;
   esac
}

blacklist()
{
   grep -Fvs "$(cat << EOF
return
snd_dlsym_link
snd_pcm_hw_strategy
__SND_DLSYM_VERSION
EOF
)"
}

match()
{
   blacklist | grep -Eh '^(static|__inline__|const|struct|unsigned| )*[a-zA-Z_]+[\t \*]*[a-zA-Z_]+\(.*\);'
}

preprocess()
{
   # trim leading whitespace and turn function definitions oneline and remove attributes
   sed 's/^[\t ]*//;s/[\t ]*__attribute__((.*))[\t ]*//g' | sed -z 's/,[\t ]*\n/, /g'
}

cat include/alsa/*.h | preprocess | match | tr -d ';' | while read -r fun; do
   name="$(fun_name_for "$fun")"
   grep -Fqs "$name(" libasound.c || printf '%s { WARNX1("stub"); %s }\n' "$fun" "$(return_for "$fun" "$name")"
done
