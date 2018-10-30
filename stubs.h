const char *snd_config_topdir(void) { WARNX1("stub"); return NULL; }
int snd_config_top(snd_config_t **config) { WARNX1("stub"); return -1; }
int snd_config_load(snd_config_t *config, snd_input_t *in) { WARNX1("stub"); return -1; }
int snd_config_load_override(snd_config_t *config, snd_input_t *in) { WARNX1("stub"); return -1; }
int snd_config_save(snd_config_t *config, snd_output_t *out) { WARNX1("stub"); return -1; }
int snd_config_update(void) { WARNX1("stub"); return -1; }
int snd_config_update_r(snd_config_t **top, snd_config_update_t **update, const char *path) { WARNX1("stub"); return -1; }
int snd_config_update_free(snd_config_update_t *update) { WARNX1("stub"); return -1; }
int snd_config_update_free_global(void) { WARNX1("stub"); return -1; }
int snd_config_update_ref(snd_config_t **top) { WARNX1("stub"); return -1; }
void snd_config_ref(snd_config_t *top) { WARNX1("stub");  }
void snd_config_unref(snd_config_t *top) { WARNX1("stub");  }
int snd_config_search(snd_config_t *config, const char *key, snd_config_t **result) { WARNX1("stub"); return -1; }
int snd_config_searchv(snd_config_t *config, snd_config_t **result, ...) { WARNX1("stub"); return -1; }
int snd_config_search_definition(snd_config_t *config, const char *base, const char *key, snd_config_t **result) { WARNX1("stub"); return -1; }
int snd_config_expand(snd_config_t *config, snd_config_t *root, const char *args, snd_config_t *private_data, snd_config_t **result) { WARNX1("stub"); return -1; }
int snd_config_evaluate(snd_config_t *config, snd_config_t *root, snd_config_t *private_data, snd_config_t **result) { WARNX1("stub"); return -1; }
int snd_config_add(snd_config_t *config, snd_config_t *leaf) { WARNX1("stub"); return -1; }
int snd_config_delete(snd_config_t *config) { WARNX1("stub"); return -1; }
int snd_config_delete_compound_members(const snd_config_t *config) { WARNX1("stub"); return -1; }
int snd_config_copy(snd_config_t **dst, snd_config_t *src) { WARNX1("stub"); return -1; }
int snd_config_make(snd_config_t **config, const char *key, snd_config_type_t type) { WARNX1("stub"); return -1; }
int snd_config_make_integer(snd_config_t **config, const char *key) { WARNX1("stub"); return -1; }
int snd_config_make_real(snd_config_t **config, const char *key) { WARNX1("stub"); return -1; }
int snd_config_make_string(snd_config_t **config, const char *key) { WARNX1("stub"); return -1; }
int snd_config_make_pointer(snd_config_t **config, const char *key) { WARNX1("stub"); return -1; }
int snd_config_make_compound(snd_config_t **config, const char *key, int join) { WARNX1("stub"); return -1; }
int snd_config_imake_integer(snd_config_t **config, const char *key, const long value) { WARNX1("stub"); return -1; }
int snd_config_imake_real(snd_config_t **config, const char *key, const double value) { WARNX1("stub"); return -1; }
int snd_config_imake_string(snd_config_t **config, const char *key, const char *ascii) { WARNX1("stub"); return -1; }
int snd_config_imake_safe_string(snd_config_t **config, const char *key, const char *ascii) { WARNX1("stub"); return -1; }
int snd_config_imake_pointer(snd_config_t **config, const char *key, const void *ptr) { WARNX1("stub"); return -1; }
snd_config_type_t snd_config_get_type(const snd_config_t *config) { WARNX1("stub"); return -1; }
int snd_config_set_id(snd_config_t *config, const char *id) { WARNX1("stub"); return -1; }
int snd_config_set_integer(snd_config_t *config, long value) { WARNX1("stub"); return -1; }
int snd_config_set_real(snd_config_t *config, double value) { WARNX1("stub"); return -1; }
int snd_config_set_string(snd_config_t *config, const char *value) { WARNX1("stub"); return -1; }
int snd_config_set_ascii(snd_config_t *config, const char *ascii) { WARNX1("stub"); return -1; }
int snd_config_set_pointer(snd_config_t *config, const void *ptr) { WARNX1("stub"); return -1; }
int snd_config_get_id(const snd_config_t *config, const char **value) { WARNX1("stub"); return -1; }
int snd_config_get_integer(const snd_config_t *config, long *value) { WARNX1("stub"); return -1; }
int snd_config_get_real(const snd_config_t *config, double *value) { WARNX1("stub"); return -1; }
int snd_config_get_ireal(const snd_config_t *config, double *value) { WARNX1("stub"); return -1; }
int snd_config_get_string(const snd_config_t *config, const char **value) { WARNX1("stub"); return -1; }
int snd_config_get_ascii(const snd_config_t *config, char **value) { WARNX1("stub"); return -1; }
int snd_config_get_pointer(const snd_config_t *config, const void **value) { WARNX1("stub"); return -1; }
int snd_config_test_id(const snd_config_t *config, const char *id) { WARNX1("stub"); return -1; }
snd_config_iterator_t snd_config_iterator_first(const snd_config_t *node) { WARNX1("stub"); return NULL; }
snd_config_iterator_t snd_config_iterator_next(const snd_config_iterator_t iterator) { WARNX1("stub"); return NULL; }
snd_config_iterator_t snd_config_iterator_end(const snd_config_t *node) { WARNX1("stub"); return NULL; }
snd_config_t *snd_config_iterator_entry(const snd_config_iterator_t iterator) { WARNX1("stub"); return NULL; }
int snd_config_get_bool_ascii(const char *ascii) { WARNX1("stub"); return -1; }
int snd_config_get_bool(const snd_config_t *conf) { WARNX1("stub"); return -1; }
int snd_config_get_ctl_iface_ascii(const char *ascii) { WARNX1("stub"); return -1; }
int snd_config_get_ctl_iface(const snd_config_t *conf) { WARNX1("stub"); return -1; }
int snd_names_list(const char *iface, snd_devname_t **list) { WARNX1("stub"); return 0; }
void snd_names_list_free(snd_devname_t *list) { WARNX1("stub");  }
int snd_card_load(int card) { WARNX1("stub"); return -1; }
int snd_card_next(int *card) { WARNX1("stub"); return -1; }
int snd_card_get_index(const char *name) { WARNX1("stub"); return -1; }
int snd_card_get_name(int card, char **name) { WARNX1("stub"); return -1; }
int snd_card_get_longname(int card, char **name) { WARNX1("stub"); return -1; }
int snd_ctl_open(snd_ctl_t **ctl, const char *name, int mode) { WARNX1("stub"); return 0; }
int snd_ctl_open_lconf(snd_ctl_t **ctl, const char *name, int mode, snd_config_t *lconf) { WARNX1("stub"); return 0; }
int snd_ctl_open_fallback(snd_ctl_t **ctl, snd_config_t *root, const char *name, const char *orig_name, int mode) { WARNX1("stub"); return 0; }
int snd_ctl_close(snd_ctl_t *ctl) { WARNX1("stub"); return 0; }
int snd_ctl_nonblock(snd_ctl_t *ctl, int nonblock) { WARNX1("stub"); return 0; }
int snd_async_add_ctl_handler(snd_async_handler_t **handler, snd_ctl_t *ctl, snd_async_callback_t callback, void *private_data) { WARNX1("stub"); return 0; }
snd_ctl_t *snd_async_handler_get_ctl(snd_async_handler_t *handler) { WARNX1("stub"); return NULL; }
int snd_ctl_poll_descriptors_count(snd_ctl_t *ctl) { WARNX1("stub"); return 0; }
int snd_ctl_poll_descriptors(snd_ctl_t *ctl, struct pollfd *pfds, unsigned int space) { WARNX1("stub"); return 0; }
int snd_ctl_poll_descriptors_revents(snd_ctl_t *ctl, struct pollfd *pfds, unsigned int nfds, unsigned short *revents) { WARNX1("stub"); return 0; }
int snd_ctl_subscribe_events(snd_ctl_t *ctl, int subscribe) { WARNX1("stub"); return 0; }
int snd_ctl_card_info(snd_ctl_t *ctl, snd_ctl_card_info_t *info) { WARNX1("stub"); return 0; }
int snd_ctl_elem_list(snd_ctl_t *ctl, snd_ctl_elem_list_t *list) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info(snd_ctl_t *ctl, snd_ctl_elem_info_t *info) { WARNX1("stub"); return 0; }
int snd_ctl_elem_read(snd_ctl_t *ctl, snd_ctl_elem_value_t *data) { WARNX1("stub"); return 0; }
int snd_ctl_elem_write(snd_ctl_t *ctl, snd_ctl_elem_value_t *data) { WARNX1("stub"); return 0; }
int snd_ctl_elem_lock(snd_ctl_t *ctl, snd_ctl_elem_id_t *id) { WARNX1("stub"); return 0; }
int snd_ctl_elem_unlock(snd_ctl_t *ctl, snd_ctl_elem_id_t *id) { WARNX1("stub"); return 0; }
int snd_ctl_elem_tlv_read(snd_ctl_t *ctl, const snd_ctl_elem_id_t *id, unsigned int *tlv, unsigned int tlv_size) { WARNX1("stub"); return 0; }
int snd_ctl_elem_tlv_write(snd_ctl_t *ctl, const snd_ctl_elem_id_t *id, const unsigned int *tlv) { WARNX1("stub"); return 0; }
int snd_ctl_elem_tlv_command(snd_ctl_t *ctl, const snd_ctl_elem_id_t *id, const unsigned int *tlv) { WARNX1("stub"); return 0; }
int snd_ctl_hwdep_next_device(snd_ctl_t *ctl, int * device) { WARNX1("stub"); return 0; }
int snd_ctl_hwdep_info(snd_ctl_t *ctl, snd_hwdep_info_t * info) { WARNX1("stub"); return 0; }
int snd_ctl_pcm_next_device(snd_ctl_t *ctl, int *device) { WARNX1("stub"); return 0; }
int snd_ctl_pcm_info(snd_ctl_t *ctl, snd_pcm_info_t * info) { WARNX1("stub"); return 0; }
int snd_ctl_pcm_prefer_subdevice(snd_ctl_t *ctl, int subdev) { WARNX1("stub"); return 0; }
int snd_ctl_rawmidi_next_device(snd_ctl_t *ctl, int * device) { WARNX1("stub"); return 0; }
int snd_ctl_rawmidi_info(snd_ctl_t *ctl, snd_rawmidi_info_t * info) { WARNX1("stub"); return 0; }
int snd_ctl_rawmidi_prefer_subdevice(snd_ctl_t *ctl, int subdev) { WARNX1("stub"); return 0; }
int snd_ctl_set_power_state(snd_ctl_t *ctl, unsigned int state) { WARNX1("stub"); return 0; }
int snd_ctl_get_power_state(snd_ctl_t *ctl, unsigned int *state) { WARNX1("stub"); return 0; }
int snd_ctl_read(snd_ctl_t *ctl, snd_ctl_event_t *event) { WARNX1("stub"); return 0; }
int snd_ctl_wait(snd_ctl_t *ctl, int timeout) { WARNX1("stub"); return 0; }
const char *snd_ctl_name(snd_ctl_t *ctl) { WARNX1("stub"); return NULL; }
snd_ctl_type_t snd_ctl_type(snd_ctl_t *ctl) { WARNX1("stub"); return 0; }
const char *snd_ctl_elem_type_name(snd_ctl_elem_type_t type) { WARNX1("stub"); return NULL; }
const char *snd_ctl_elem_iface_name(snd_ctl_elem_iface_t iface) { WARNX1("stub"); return NULL; }
const char *snd_ctl_event_type_name(snd_ctl_event_type_t type) { WARNX1("stub"); return NULL; }
unsigned int snd_ctl_event_elem_get_mask(const snd_ctl_event_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_event_elem_get_numid(const snd_ctl_event_t *obj) { WARNX1("stub"); return 0; }
void snd_ctl_event_elem_get_id(const snd_ctl_event_t *obj, snd_ctl_elem_id_t *ptr) { WARNX1("stub");  }
snd_ctl_elem_iface_t snd_ctl_event_elem_get_interface(const snd_ctl_event_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_event_elem_get_device(const snd_ctl_event_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_event_elem_get_subdevice(const snd_ctl_event_t *obj) { WARNX1("stub"); return 0; }
const char *snd_ctl_event_elem_get_name(const snd_ctl_event_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_ctl_event_elem_get_index(const snd_ctl_event_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_list_alloc_space(snd_ctl_elem_list_t *obj, unsigned int entries) { WARNX1("stub"); return 0; }
void snd_ctl_elem_list_free_space(snd_ctl_elem_list_t *obj) { WARNX1("stub");  }
char *snd_ctl_ascii_elem_id_get(snd_ctl_elem_id_t *id) { WARNX1("stub"); return NULL; }
int snd_ctl_ascii_elem_id_parse(snd_ctl_elem_id_t *dst, const char *str) { WARNX1("stub"); return 0; }
int snd_ctl_ascii_value_parse(snd_ctl_t *handle, snd_ctl_elem_value_t *dst, snd_ctl_elem_info_t *info, const char *value) { WARNX1("stub"); return 0; }
size_t snd_ctl_elem_id_sizeof(void) { WARNX1("stub"); return 0; }
int snd_ctl_elem_id_malloc(snd_ctl_elem_id_t **ptr) { WARNX1("stub"); return 0; }
void snd_ctl_elem_id_free(snd_ctl_elem_id_t *obj) { WARNX1("stub");  }
void snd_ctl_elem_id_clear(snd_ctl_elem_id_t *obj) { WARNX1("stub");  }
void snd_ctl_elem_id_copy(snd_ctl_elem_id_t *dst, const snd_ctl_elem_id_t *src) { WARNX1("stub");  }
unsigned int snd_ctl_elem_id_get_numid(const snd_ctl_elem_id_t *obj) { WARNX1("stub"); return 0; }
snd_ctl_elem_iface_t snd_ctl_elem_id_get_interface(const snd_ctl_elem_id_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_id_get_device(const snd_ctl_elem_id_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_id_get_subdevice(const snd_ctl_elem_id_t *obj) { WARNX1("stub"); return 0; }
const char *snd_ctl_elem_id_get_name(const snd_ctl_elem_id_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_ctl_elem_id_get_index(const snd_ctl_elem_id_t *obj) { WARNX1("stub"); return 0; }
void snd_ctl_elem_id_set_numid(snd_ctl_elem_id_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_id_set_interface(snd_ctl_elem_id_t *obj, snd_ctl_elem_iface_t val) { WARNX1("stub");  }
void snd_ctl_elem_id_set_device(snd_ctl_elem_id_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_id_set_subdevice(snd_ctl_elem_id_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_id_set_name(snd_ctl_elem_id_t *obj, const char *val) { WARNX1("stub");  }
void snd_ctl_elem_id_set_index(snd_ctl_elem_id_t *obj, unsigned int val) { WARNX1("stub");  }
size_t snd_ctl_card_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_ctl_card_info_malloc(snd_ctl_card_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_ctl_card_info_free(snd_ctl_card_info_t *obj) { WARNX1("stub");  }
void snd_ctl_card_info_clear(snd_ctl_card_info_t *obj) { WARNX1("stub");  }
void snd_ctl_card_info_copy(snd_ctl_card_info_t *dst, const snd_ctl_card_info_t *src) { WARNX1("stub");  }
int snd_ctl_card_info_get_card(const snd_ctl_card_info_t *obj) { WARNX1("stub"); return 0; }
const char *snd_ctl_card_info_get_id(const snd_ctl_card_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_ctl_card_info_get_driver(const snd_ctl_card_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_ctl_card_info_get_name(const snd_ctl_card_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_ctl_card_info_get_longname(const snd_ctl_card_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_ctl_card_info_get_mixername(const snd_ctl_card_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_ctl_card_info_get_components(const snd_ctl_card_info_t *obj) { WARNX1("stub"); return NULL; }
size_t snd_ctl_event_sizeof(void) { WARNX1("stub"); return 0; }
int snd_ctl_event_malloc(snd_ctl_event_t **ptr) { WARNX1("stub"); return 0; }
void snd_ctl_event_free(snd_ctl_event_t *obj) { WARNX1("stub");  }
void snd_ctl_event_clear(snd_ctl_event_t *obj) { WARNX1("stub");  }
void snd_ctl_event_copy(snd_ctl_event_t *dst, const snd_ctl_event_t *src) { WARNX1("stub");  }
snd_ctl_event_type_t snd_ctl_event_get_type(const snd_ctl_event_t *obj) { WARNX1("stub"); return 0; }
size_t snd_ctl_elem_list_sizeof(void) { WARNX1("stub"); return 0; }
int snd_ctl_elem_list_malloc(snd_ctl_elem_list_t **ptr) { WARNX1("stub"); return 0; }
void snd_ctl_elem_list_free(snd_ctl_elem_list_t *obj) { WARNX1("stub");  }
void snd_ctl_elem_list_clear(snd_ctl_elem_list_t *obj) { WARNX1("stub");  }
void snd_ctl_elem_list_copy(snd_ctl_elem_list_t *dst, const snd_ctl_elem_list_t *src) { WARNX1("stub");  }
void snd_ctl_elem_list_set_offset(snd_ctl_elem_list_t *obj, unsigned int val) { WARNX1("stub");  }
unsigned int snd_ctl_elem_list_get_used(const snd_ctl_elem_list_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_list_get_count(const snd_ctl_elem_list_t *obj) { WARNX1("stub"); return 0; }
void snd_ctl_elem_list_get_id(const snd_ctl_elem_list_t *obj, unsigned int idx, snd_ctl_elem_id_t *ptr) { WARNX1("stub");  }
unsigned int snd_ctl_elem_list_get_numid(const snd_ctl_elem_list_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
snd_ctl_elem_iface_t snd_ctl_elem_list_get_interface(const snd_ctl_elem_list_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_list_get_device(const snd_ctl_elem_list_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_list_get_subdevice(const snd_ctl_elem_list_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
const char *snd_ctl_elem_list_get_name(const snd_ctl_elem_list_t *obj, unsigned int idx) { WARNX1("stub"); return NULL; }
unsigned int snd_ctl_elem_list_get_index(const snd_ctl_elem_list_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
size_t snd_ctl_elem_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_malloc(snd_ctl_elem_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_ctl_elem_info_free(snd_ctl_elem_info_t *obj) { WARNX1("stub");  }
void snd_ctl_elem_info_clear(snd_ctl_elem_info_t *obj) { WARNX1("stub");  }
void snd_ctl_elem_info_copy(snd_ctl_elem_info_t *dst, const snd_ctl_elem_info_t *src) { WARNX1("stub");  }
snd_ctl_elem_type_t snd_ctl_elem_info_get_type(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_readable(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_writable(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_volatile(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_inactive(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_locked(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_tlv_readable(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_tlv_writable(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_tlv_commandable(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_owner(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_is_user(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
pid_t snd_ctl_elem_info_get_owner(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_info_get_count(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
long snd_ctl_elem_info_get_min(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
long snd_ctl_elem_info_get_max(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
long snd_ctl_elem_info_get_step(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_info_get_items(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
void snd_ctl_elem_info_set_item(snd_ctl_elem_info_t *obj, unsigned int val) { WARNX1("stub");  }
const char *snd_ctl_elem_info_get_item_name(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return NULL; }
int snd_ctl_elem_info_get_dimensions(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_get_dimension(const snd_ctl_elem_info_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
int snd_ctl_elem_info_set_dimension(snd_ctl_elem_info_t *info, const int dimension[4]) { WARNX1("stub"); return 0; }
void snd_ctl_elem_info_get_id(const snd_ctl_elem_info_t *obj, snd_ctl_elem_id_t *ptr) { WARNX1("stub");  }
unsigned int snd_ctl_elem_info_get_numid(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
snd_ctl_elem_iface_t snd_ctl_elem_info_get_interface(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_info_get_device(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_info_get_subdevice(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
const char *snd_ctl_elem_info_get_name(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_ctl_elem_info_get_index(const snd_ctl_elem_info_t *obj) { WARNX1("stub"); return 0; }
void snd_ctl_elem_info_set_id(snd_ctl_elem_info_t *obj, const snd_ctl_elem_id_t *ptr) { WARNX1("stub");  }
void snd_ctl_elem_info_set_numid(snd_ctl_elem_info_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_info_set_interface(snd_ctl_elem_info_t *obj, snd_ctl_elem_iface_t val) { WARNX1("stub");  }
void snd_ctl_elem_info_set_device(snd_ctl_elem_info_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_info_set_subdevice(snd_ctl_elem_info_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_info_set_name(snd_ctl_elem_info_t *obj, const char *val) { WARNX1("stub");  }
void snd_ctl_elem_info_set_index(snd_ctl_elem_info_t *obj, unsigned int val) { WARNX1("stub");  }
int snd_ctl_add_integer_elem_set(snd_ctl_t *ctl, snd_ctl_elem_info_t *info, unsigned int element_count, unsigned int member_count, long min, long max, long step) { WARNX1("stub"); return 0; }
int snd_ctl_add_boolean_elem_set(snd_ctl_t *ctl, snd_ctl_elem_info_t *info, unsigned int element_count, unsigned int member_count) { WARNX1("stub"); return 0; }
int snd_ctl_add_enumerated_elem_set(snd_ctl_t *ctl, snd_ctl_elem_info_t *info, unsigned int element_count, unsigned int member_count, unsigned int items, const char *const labels[]) { WARNX1("stub"); return 0; }
int snd_ctl_add_bytes_elem_set(snd_ctl_t *ctl, snd_ctl_elem_info_t *info, unsigned int element_count, unsigned int member_count) { WARNX1("stub"); return 0; }
int snd_ctl_elem_add_integer(snd_ctl_t *ctl, const snd_ctl_elem_id_t *id, unsigned int count, long imin, long imax, long istep) { WARNX1("stub"); return 0; }
int snd_ctl_elem_add_boolean(snd_ctl_t *ctl, const snd_ctl_elem_id_t *id, unsigned int count) { WARNX1("stub"); return 0; }
int snd_ctl_elem_add_enumerated(snd_ctl_t *ctl, const snd_ctl_elem_id_t *id, unsigned int count, unsigned int items, const char *const names[]) { WARNX1("stub"); return 0; }
int snd_ctl_elem_remove(snd_ctl_t *ctl, snd_ctl_elem_id_t *id) { WARNX1("stub"); return 0; }
size_t snd_ctl_elem_value_sizeof(void) { WARNX1("stub"); return 0; }
int snd_ctl_elem_value_malloc(snd_ctl_elem_value_t **ptr) { WARNX1("stub"); return 0; }
void snd_ctl_elem_value_free(snd_ctl_elem_value_t *obj) { WARNX1("stub");  }
void snd_ctl_elem_value_clear(snd_ctl_elem_value_t *obj) { WARNX1("stub");  }
void snd_ctl_elem_value_copy(snd_ctl_elem_value_t *dst, const snd_ctl_elem_value_t *src) { WARNX1("stub");  }
int snd_ctl_elem_value_compare(snd_ctl_elem_value_t *left, const snd_ctl_elem_value_t *right) { WARNX1("stub"); return 0; }
void snd_ctl_elem_value_get_id(const snd_ctl_elem_value_t *obj, snd_ctl_elem_id_t *ptr) { WARNX1("stub");  }
unsigned int snd_ctl_elem_value_get_numid(const snd_ctl_elem_value_t *obj) { WARNX1("stub"); return 0; }
snd_ctl_elem_iface_t snd_ctl_elem_value_get_interface(const snd_ctl_elem_value_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_value_get_device(const snd_ctl_elem_value_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_value_get_subdevice(const snd_ctl_elem_value_t *obj) { WARNX1("stub"); return 0; }
const char *snd_ctl_elem_value_get_name(const snd_ctl_elem_value_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_ctl_elem_value_get_index(const snd_ctl_elem_value_t *obj) { WARNX1("stub"); return 0; }
void snd_ctl_elem_value_set_id(snd_ctl_elem_value_t *obj, const snd_ctl_elem_id_t *ptr) { WARNX1("stub");  }
void snd_ctl_elem_value_set_numid(snd_ctl_elem_value_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_value_set_interface(snd_ctl_elem_value_t *obj, snd_ctl_elem_iface_t val) { WARNX1("stub");  }
void snd_ctl_elem_value_set_device(snd_ctl_elem_value_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_value_set_subdevice(snd_ctl_elem_value_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_value_set_name(snd_ctl_elem_value_t *obj, const char *val) { WARNX1("stub");  }
void snd_ctl_elem_value_set_index(snd_ctl_elem_value_t *obj, unsigned int val) { WARNX1("stub");  }
int snd_ctl_elem_value_get_boolean(const snd_ctl_elem_value_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
long snd_ctl_elem_value_get_integer(const snd_ctl_elem_value_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
unsigned int snd_ctl_elem_value_get_enumerated(const snd_ctl_elem_value_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
unsigned char snd_ctl_elem_value_get_byte(const snd_ctl_elem_value_t *obj, unsigned int idx) { WARNX1("stub"); return 0; }
void snd_ctl_elem_value_set_boolean(snd_ctl_elem_value_t *obj, unsigned int idx, long val) { WARNX1("stub");  }
void snd_ctl_elem_value_set_integer(snd_ctl_elem_value_t *obj, unsigned int idx, long val) { WARNX1("stub");  }
void snd_ctl_elem_value_set_enumerated(snd_ctl_elem_value_t *obj, unsigned int idx, unsigned int val) { WARNX1("stub");  }
void snd_ctl_elem_value_set_byte(snd_ctl_elem_value_t *obj, unsigned int idx, unsigned char val) { WARNX1("stub");  }
void snd_ctl_elem_set_bytes(snd_ctl_elem_value_t *obj, void *data, size_t size) { WARNX1("stub");  }
const void * snd_ctl_elem_value_get_bytes(const snd_ctl_elem_value_t *obj) { WARNX1("stub"); return NULL; }
int snd_hctl_compare_fast(const snd_hctl_elem_t *c1, const snd_hctl_elem_t *c2) { WARNX1("stub"); return 0; }
int snd_hctl_open(snd_hctl_t **hctl, const char *name, int mode) { WARNX1("stub"); return 0; }
int snd_hctl_open_ctl(snd_hctl_t **hctlp, snd_ctl_t *ctl) { WARNX1("stub"); return 0; }
int snd_hctl_close(snd_hctl_t *hctl) { WARNX1("stub"); return 0; }
int snd_hctl_nonblock(snd_hctl_t *hctl, int nonblock) { WARNX1("stub"); return 0; }
int snd_hctl_poll_descriptors_count(snd_hctl_t *hctl) { WARNX1("stub"); return 0; }
int snd_hctl_poll_descriptors(snd_hctl_t *hctl, struct pollfd *pfds, unsigned int space) { WARNX1("stub"); return 0; }
int snd_hctl_poll_descriptors_revents(snd_hctl_t *ctl, struct pollfd *pfds, unsigned int nfds, unsigned short *revents) { WARNX1("stub"); return 0; }
unsigned int snd_hctl_get_count(snd_hctl_t *hctl) { WARNX1("stub"); return 0; }
int snd_hctl_set_compare(snd_hctl_t *hctl, snd_hctl_compare_t hsort) { WARNX1("stub"); return 0; }
snd_hctl_elem_t *snd_hctl_first_elem(snd_hctl_t *hctl) { WARNX1("stub"); return NULL; }
snd_hctl_elem_t *snd_hctl_last_elem(snd_hctl_t *hctl) { WARNX1("stub"); return NULL; }
snd_hctl_elem_t *snd_hctl_find_elem(snd_hctl_t *hctl, const snd_ctl_elem_id_t *id) { WARNX1("stub"); return NULL; }
void snd_hctl_set_callback(snd_hctl_t *hctl, snd_hctl_callback_t callback) { WARNX1("stub");  }
void snd_hctl_set_callback_private(snd_hctl_t *hctl, void *data) { WARNX1("stub");  }
void *snd_hctl_get_callback_private(snd_hctl_t *hctl) { WARNX1("stub"); return NULL; }
int snd_hctl_load(snd_hctl_t *hctl) { WARNX1("stub"); return 0; }
int snd_hctl_free(snd_hctl_t *hctl) { WARNX1("stub"); return 0; }
int snd_hctl_handle_events(snd_hctl_t *hctl) { WARNX1("stub"); return 0; }
const char *snd_hctl_name(snd_hctl_t *hctl) { WARNX1("stub"); return NULL; }
int snd_hctl_wait(snd_hctl_t *hctl, int timeout) { WARNX1("stub"); return 0; }
snd_ctl_t *snd_hctl_ctl(snd_hctl_t *hctl) { WARNX1("stub"); return NULL; }
snd_hctl_elem_t *snd_hctl_elem_next(snd_hctl_elem_t *elem) { WARNX1("stub"); return NULL; }
snd_hctl_elem_t *snd_hctl_elem_prev(snd_hctl_elem_t *elem) { WARNX1("stub"); return NULL; }
int snd_hctl_elem_info(snd_hctl_elem_t *elem, snd_ctl_elem_info_t * info) { WARNX1("stub"); return 0; }
int snd_hctl_elem_read(snd_hctl_elem_t *elem, snd_ctl_elem_value_t * value) { WARNX1("stub"); return 0; }
int snd_hctl_elem_write(snd_hctl_elem_t *elem, snd_ctl_elem_value_t * value) { WARNX1("stub"); return 0; }
int snd_hctl_elem_tlv_read(snd_hctl_elem_t *elem, unsigned int *tlv, unsigned int tlv_size) { WARNX1("stub"); return 0; }
int snd_hctl_elem_tlv_write(snd_hctl_elem_t *elem, const unsigned int *tlv) { WARNX1("stub"); return 0; }
int snd_hctl_elem_tlv_command(snd_hctl_elem_t *elem, const unsigned int *tlv) { WARNX1("stub"); return 0; }
snd_hctl_t *snd_hctl_elem_get_hctl(snd_hctl_elem_t *elem) { WARNX1("stub"); return NULL; }
void snd_hctl_elem_get_id(const snd_hctl_elem_t *obj, snd_ctl_elem_id_t *ptr) { WARNX1("stub");  }
unsigned int snd_hctl_elem_get_numid(const snd_hctl_elem_t *obj) { WARNX1("stub"); return 0; }
snd_ctl_elem_iface_t snd_hctl_elem_get_interface(const snd_hctl_elem_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_hctl_elem_get_device(const snd_hctl_elem_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_hctl_elem_get_subdevice(const snd_hctl_elem_t *obj) { WARNX1("stub"); return 0; }
const char *snd_hctl_elem_get_name(const snd_hctl_elem_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_hctl_elem_get_index(const snd_hctl_elem_t *obj) { WARNX1("stub"); return 0; }
void snd_hctl_elem_set_callback(snd_hctl_elem_t *obj, snd_hctl_elem_callback_t val) { WARNX1("stub");  }
void * snd_hctl_elem_get_callback_private(const snd_hctl_elem_t *obj) { WARNX1("stub"); return NULL; }
void snd_hctl_elem_set_callback_private(snd_hctl_elem_t *obj, void * val) { WARNX1("stub");  }
int snd_sctl_build(snd_sctl_t **ctl, snd_ctl_t *handle, snd_config_t *config, snd_config_t *private_data, int mode) { WARNX1("stub"); return 0; }
int snd_sctl_free(snd_sctl_t *handle) { WARNX1("stub"); return 0; }
int snd_sctl_install(snd_sctl_t *handle) { WARNX1("stub"); return 0; }
int snd_sctl_remove(snd_sctl_t *handle) { WARNX1("stub"); return 0; }
int snd_ctl_ext_create(snd_ctl_ext_t *ext, const char *name, int mode) { WARNX1("stub"); return 0; }
int snd_ctl_ext_delete(snd_ctl_ext_t *ext) { WARNX1("stub"); return 0; }
snd_local_error_handler_t snd_lib_error_set_local(snd_local_error_handler_t func) { WARNX1("stub"); return 0; }
void *snd_dlopen(const char *file, int mode, char *errbuf, size_t errbuflen) { WARNX1("stub"); return NULL; }
void *snd_dlsym(void *handle, const char *name, const char *version) { WARNX1("stub"); return NULL; }
int snd_dlclose(void *handle) { WARNX1("stub"); return 0; }
int snd_async_add_handler(snd_async_handler_t **handler, int fd, snd_async_callback_t callback, void *private_data) { WARNX1("stub"); return 0; }
int snd_async_del_handler(snd_async_handler_t *handler) { WARNX1("stub"); return 0; }
int snd_async_handler_get_fd(snd_async_handler_t *handler) { WARNX1("stub"); return 0; }
int snd_async_handler_get_signo(snd_async_handler_t *handler) { WARNX1("stub"); return 0; }
void *snd_async_handler_get_callback_private(snd_async_handler_t *handler) { WARNX1("stub"); return NULL; }
struct snd_shm_area *snd_shm_area_create(int shmid, void *ptr) { WARNX1("stub"); return NULL; }
struct snd_shm_area *snd_shm_area_share(struct snd_shm_area *area) { WARNX1("stub"); return NULL; }
int snd_shm_area_destroy(struct snd_shm_area *area) { WARNX1("stub"); return 0; }
int snd_user_file(const char *file, char **result) { WARNX1("stub"); return 0; }
int snd_hwdep_open(snd_hwdep_t **hwdep, const char *name, int mode) { WARNX1("stub"); return 0; }
int snd_hwdep_close(snd_hwdep_t *hwdep) { WARNX1("stub"); return 0; }
int snd_hwdep_poll_descriptors(snd_hwdep_t *hwdep, struct pollfd *pfds, unsigned int space) { WARNX1("stub"); return 0; }
int snd_hwdep_poll_descriptors_count(snd_hwdep_t *hwdep) { WARNX1("stub"); return 0; }
int snd_hwdep_poll_descriptors_revents(snd_hwdep_t *hwdep, struct pollfd *pfds, unsigned int nfds, unsigned short *revents) { WARNX1("stub"); return 0; }
int snd_hwdep_nonblock(snd_hwdep_t *hwdep, int nonblock) { WARNX1("stub"); return 0; }
int snd_hwdep_info(snd_hwdep_t *hwdep, snd_hwdep_info_t * info) { WARNX1("stub"); return 0; }
int snd_hwdep_dsp_status(snd_hwdep_t *hwdep, snd_hwdep_dsp_status_t *status) { WARNX1("stub"); return 0; }
int snd_hwdep_dsp_load(snd_hwdep_t *hwdep, snd_hwdep_dsp_image_t *block) { WARNX1("stub"); return 0; }
int snd_hwdep_ioctl(snd_hwdep_t *hwdep, unsigned int request, void * arg) { WARNX1("stub"); return 0; }
ssize_t snd_hwdep_write(snd_hwdep_t *hwdep, const void *buffer, size_t size) { WARNX1("stub"); return 0; }
ssize_t snd_hwdep_read(snd_hwdep_t *hwdep, void *buffer, size_t size) { WARNX1("stub"); return 0; }
size_t snd_hwdep_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_hwdep_info_malloc(snd_hwdep_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_hwdep_info_free(snd_hwdep_info_t *obj) { WARNX1("stub");  }
void snd_hwdep_info_copy(snd_hwdep_info_t *dst, const snd_hwdep_info_t *src) { WARNX1("stub");  }
unsigned int snd_hwdep_info_get_device(const snd_hwdep_info_t *obj) { WARNX1("stub"); return 0; }
int snd_hwdep_info_get_card(const snd_hwdep_info_t *obj) { WARNX1("stub"); return 0; }
const char *snd_hwdep_info_get_id(const snd_hwdep_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_hwdep_info_get_name(const snd_hwdep_info_t *obj) { WARNX1("stub"); return NULL; }
snd_hwdep_iface_t snd_hwdep_info_get_iface(const snd_hwdep_info_t *obj) { WARNX1("stub"); return 0; }
void snd_hwdep_info_set_device(snd_hwdep_info_t *obj, unsigned int val) { WARNX1("stub");  }
size_t snd_hwdep_dsp_status_sizeof(void) { WARNX1("stub"); return 0; }
int snd_hwdep_dsp_status_malloc(snd_hwdep_dsp_status_t **ptr) { WARNX1("stub"); return 0; }
void snd_hwdep_dsp_status_free(snd_hwdep_dsp_status_t *obj) { WARNX1("stub");  }
void snd_hwdep_dsp_status_copy(snd_hwdep_dsp_status_t *dst, const snd_hwdep_dsp_status_t *src) { WARNX1("stub");  }
unsigned int snd_hwdep_dsp_status_get_version(const snd_hwdep_dsp_status_t *obj) { WARNX1("stub"); return 0; }
const char *snd_hwdep_dsp_status_get_id(const snd_hwdep_dsp_status_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_hwdep_dsp_status_get_num_dsps(const snd_hwdep_dsp_status_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_hwdep_dsp_status_get_dsp_loaded(const snd_hwdep_dsp_status_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_hwdep_dsp_status_get_chip_ready(const snd_hwdep_dsp_status_t *obj) { WARNX1("stub"); return 0; }
size_t snd_hwdep_dsp_image_sizeof(void) { WARNX1("stub"); return 0; }
int snd_hwdep_dsp_image_malloc(snd_hwdep_dsp_image_t **ptr) { WARNX1("stub"); return 0; }
void snd_hwdep_dsp_image_free(snd_hwdep_dsp_image_t *obj) { WARNX1("stub");  }
void snd_hwdep_dsp_image_copy(snd_hwdep_dsp_image_t *dst, const snd_hwdep_dsp_image_t *src) { WARNX1("stub");  }
unsigned int snd_hwdep_dsp_image_get_index(const snd_hwdep_dsp_image_t *obj) { WARNX1("stub"); return 0; }
const char *snd_hwdep_dsp_image_get_name(const snd_hwdep_dsp_image_t *obj) { WARNX1("stub"); return NULL; }
const void *snd_hwdep_dsp_image_get_image(const snd_hwdep_dsp_image_t *obj) { WARNX1("stub"); return NULL; }
size_t snd_hwdep_dsp_image_get_length(const snd_hwdep_dsp_image_t *obj) { WARNX1("stub"); return 0; }
void snd_hwdep_dsp_image_set_index(snd_hwdep_dsp_image_t *obj, unsigned int _index) { WARNX1("stub");  }
void snd_hwdep_dsp_image_set_name(snd_hwdep_dsp_image_t *obj, const char *name) { WARNX1("stub");  }
void snd_hwdep_dsp_image_set_image(snd_hwdep_dsp_image_t *obj, void *buffer) { WARNX1("stub");  }
void snd_hwdep_dsp_image_set_length(snd_hwdep_dsp_image_t *obj, size_t length) { WARNX1("stub");  }
int snd_input_stdio_open(snd_input_t **inputp, const char *file, const char *mode) { WARNX1("stub"); return 0; }
int snd_input_stdio_attach(snd_input_t **inputp, FILE *fp, int _close) { WARNX1("stub"); return 0; }
int snd_input_buffer_open(snd_input_t **inputp, const char *buffer, ssize_t size) { WARNX1("stub"); return 0; }
int snd_input_close(snd_input_t *input) { WARNX1("stub"); return 0; }
char *snd_input_gets(snd_input_t *input, char *str, size_t size) { WARNX1("stub"); return NULL; }
int snd_input_getc(snd_input_t *input) { WARNX1("stub"); return 0; }
int snd_input_ungetc(snd_input_t *input, int c) { WARNX1("stub"); return 0; }
int snd_mixer_open(snd_mixer_t **mixer, int mode) { WARNX1("stub"); return 0; }
int snd_mixer_close(snd_mixer_t *mixer) { WARNX1("stub"); return 0; }
snd_mixer_elem_t *snd_mixer_first_elem(snd_mixer_t *mixer) { WARNX1("stub"); return NULL; }
snd_mixer_elem_t *snd_mixer_last_elem(snd_mixer_t *mixer) { WARNX1("stub"); return NULL; }
int snd_mixer_handle_events(snd_mixer_t *mixer) { WARNX1("stub"); return 0; }
int snd_mixer_attach(snd_mixer_t *mixer, const char *name) { WARNX1("stub"); return 0; }
int snd_mixer_attach_hctl(snd_mixer_t *mixer, snd_hctl_t *hctl) { WARNX1("stub"); return 0; }
int snd_mixer_detach(snd_mixer_t *mixer, const char *name) { WARNX1("stub"); return 0; }
int snd_mixer_detach_hctl(snd_mixer_t *mixer, snd_hctl_t *hctl) { WARNX1("stub"); return 0; }
int snd_mixer_get_hctl(snd_mixer_t *mixer, const char *name, snd_hctl_t **hctl) { WARNX1("stub"); return 0; }
int snd_mixer_poll_descriptors_count(snd_mixer_t *mixer) { WARNX1("stub"); return 0; }
int snd_mixer_poll_descriptors(snd_mixer_t *mixer, struct pollfd *pfds, unsigned int space) { WARNX1("stub"); return 0; }
int snd_mixer_poll_descriptors_revents(snd_mixer_t *mixer, struct pollfd *pfds, unsigned int nfds, unsigned short *revents) { WARNX1("stub"); return 0; }
int snd_mixer_load(snd_mixer_t *mixer) { WARNX1("stub"); return 0; }
void snd_mixer_free(snd_mixer_t *mixer) { WARNX1("stub");  }
int snd_mixer_wait(snd_mixer_t *mixer, int timeout) { WARNX1("stub"); return 0; }
int snd_mixer_set_compare(snd_mixer_t *mixer, snd_mixer_compare_t msort) { WARNX1("stub"); return 0; }
void snd_mixer_set_callback(snd_mixer_t *obj, snd_mixer_callback_t val) { WARNX1("stub");  }
void * snd_mixer_get_callback_private(const snd_mixer_t *obj) { WARNX1("stub"); return NULL; }
void snd_mixer_set_callback_private(snd_mixer_t *obj, void * val) { WARNX1("stub");  }
unsigned int snd_mixer_get_count(const snd_mixer_t *obj) { WARNX1("stub"); return 0; }
int snd_mixer_class_unregister(snd_mixer_class_t *clss) { WARNX1("stub"); return 0; }
snd_mixer_elem_t *snd_mixer_elem_next(snd_mixer_elem_t *elem) { WARNX1("stub"); return NULL; }
snd_mixer_elem_t *snd_mixer_elem_prev(snd_mixer_elem_t *elem) { WARNX1("stub"); return NULL; }
void snd_mixer_elem_set_callback(snd_mixer_elem_t *obj, snd_mixer_elem_callback_t val) { WARNX1("stub");  }
void * snd_mixer_elem_get_callback_private(const snd_mixer_elem_t *obj) { WARNX1("stub"); return NULL; }
void snd_mixer_elem_set_callback_private(snd_mixer_elem_t *obj, void * val) { WARNX1("stub");  }
snd_mixer_elem_type_t snd_mixer_elem_get_type(const snd_mixer_elem_t *obj) { WARNX1("stub"); return 0; }
int snd_mixer_class_register(snd_mixer_class_t *class_, snd_mixer_t *mixer) { WARNX1("stub"); return 0; }
int snd_mixer_elem_new(snd_mixer_elem_t **elem, snd_mixer_elem_type_t type, int compare_weight, void *private_data, void (*private_free)(snd_mixer_elem_t *elem)) { WARNX1("stub"); return 0; }
int snd_mixer_elem_add(snd_mixer_elem_t *elem, snd_mixer_class_t *class_) { WARNX1("stub"); return 0; }
int snd_mixer_elem_remove(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
void snd_mixer_elem_free(snd_mixer_elem_t *elem) { WARNX1("stub");  }
int snd_mixer_elem_info(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_elem_value(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_elem_attach(snd_mixer_elem_t *melem, snd_hctl_elem_t *helem) { WARNX1("stub"); return 0; }
int snd_mixer_elem_detach(snd_mixer_elem_t *melem, snd_hctl_elem_t *helem) { WARNX1("stub"); return 0; }
int snd_mixer_elem_empty(snd_mixer_elem_t *melem) { WARNX1("stub"); return 0; }
void *snd_mixer_elem_get_private(const snd_mixer_elem_t *melem) { WARNX1("stub"); return NULL; }
size_t snd_mixer_class_sizeof(void) { WARNX1("stub"); return 0; }
int snd_mixer_class_malloc(snd_mixer_class_t **ptr) { WARNX1("stub"); return 0; }
void snd_mixer_class_free(snd_mixer_class_t *obj) { WARNX1("stub");  }
void snd_mixer_class_copy(snd_mixer_class_t *dst, const snd_mixer_class_t *src) { WARNX1("stub");  }
snd_mixer_t *snd_mixer_class_get_mixer(const snd_mixer_class_t *class_) { WARNX1("stub"); return NULL; }
snd_mixer_event_t snd_mixer_class_get_event(const snd_mixer_class_t *class_) { WARNX1("stub"); return 0; }
void *snd_mixer_class_get_private(const snd_mixer_class_t *class_) { WARNX1("stub"); return NULL; }
snd_mixer_compare_t snd_mixer_class_get_compare(const snd_mixer_class_t *class_) { WARNX1("stub"); return 0; }
int snd_mixer_class_set_event(snd_mixer_class_t *class_, snd_mixer_event_t event) { WARNX1("stub"); return 0; }
int snd_mixer_class_set_private(snd_mixer_class_t *class_, void *private_data) { WARNX1("stub"); return 0; }
int snd_mixer_class_set_private_free(snd_mixer_class_t *class_, void (*private_free)(snd_mixer_class_t *)) { WARNX1("stub"); return 0; }
int snd_mixer_class_set_compare(snd_mixer_class_t *class_, snd_mixer_compare_t compare) { WARNX1("stub"); return 0; }
const char *snd_mixer_selem_channel_name(snd_mixer_selem_channel_id_t channel) { WARNX1("stub"); return NULL; }
int snd_mixer_selem_register(snd_mixer_t *mixer, struct snd_mixer_selem_regopt *options, snd_mixer_class_t **classp) { WARNX1("stub"); return 0; }
void snd_mixer_selem_get_id(snd_mixer_elem_t *element, snd_mixer_selem_id_t *id) { WARNX1("stub");  }
const char *snd_mixer_selem_get_name(snd_mixer_elem_t *elem) { WARNX1("stub"); return NULL; }
unsigned int snd_mixer_selem_get_index(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
snd_mixer_elem_t *snd_mixer_find_selem(snd_mixer_t *mixer, const snd_mixer_selem_id_t *id) { WARNX1("stub"); return NULL; }
int snd_mixer_selem_is_active(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_is_playback_mono(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_playback_channel(snd_mixer_elem_t *obj, snd_mixer_selem_channel_id_t channel) { WARNX1("stub"); return 0; }
int snd_mixer_selem_is_capture_mono(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_capture_channel(snd_mixer_elem_t *obj, snd_mixer_selem_channel_id_t channel) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_capture_group(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_common_volume(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_playback_volume(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_playback_volume_joined(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_capture_volume(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_capture_volume_joined(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_common_switch(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_playback_switch(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_playback_switch_joined(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_capture_switch(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_capture_switch_joined(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_has_capture_switch_exclusive(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_playback_volume(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, long *value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_capture_volume(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, long *value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_playback_switch(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, int *value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_capture_switch(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, int *value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_playback_volume(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, long value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_capture_volume(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, long value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_playback_volume_all(snd_mixer_elem_t *elem, long value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_capture_volume_all(snd_mixer_elem_t *elem, long value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_playback_switch(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, int value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_capture_switch(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, int value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_playback_switch_all(snd_mixer_elem_t *elem, int value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_capture_switch_all(snd_mixer_elem_t *elem, int value) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_playback_volume_range(snd_mixer_elem_t *elem, long *min, long *max) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_playback_volume_range(snd_mixer_elem_t *elem, long min, long max) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_capture_volume_range(snd_mixer_elem_t *elem, long *min, long *max) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_capture_volume_range(snd_mixer_elem_t *elem, long min, long max) { WARNX1("stub"); return 0; }
int snd_mixer_selem_is_enumerated(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_is_enum_playback(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_is_enum_capture(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_enum_items(snd_mixer_elem_t *elem) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_enum_item_name(snd_mixer_elem_t *elem, unsigned int idx, size_t maxlen, char *str) { WARNX1("stub"); return 0; }
int snd_mixer_selem_get_enum_item(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, unsigned int *idxp) { WARNX1("stub"); return 0; }
int snd_mixer_selem_set_enum_item(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t channel, unsigned int idx) { WARNX1("stub"); return 0; }
size_t snd_mixer_selem_id_sizeof(void) { WARNX1("stub"); return 0; }
int snd_mixer_selem_id_malloc(snd_mixer_selem_id_t **ptr) { WARNX1("stub"); return 0; }
void snd_mixer_selem_id_free(snd_mixer_selem_id_t *obj) { WARNX1("stub");  }
void snd_mixer_selem_id_copy(snd_mixer_selem_id_t *dst, const snd_mixer_selem_id_t *src) { WARNX1("stub");  }
const char *snd_mixer_selem_id_get_name(const snd_mixer_selem_id_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_mixer_selem_id_get_index(const snd_mixer_selem_id_t *obj) { WARNX1("stub"); return 0; }
void snd_mixer_selem_id_set_name(snd_mixer_selem_id_t *obj, const char *val) { WARNX1("stub");  }
void snd_mixer_selem_id_set_index(snd_mixer_selem_id_t *obj, unsigned int val) { WARNX1("stub");  }
int snd_mixer_selem_compare(const snd_mixer_elem_t *c1, const snd_mixer_elem_t *c2) { WARNX1("stub"); return 0; }
int snd_mixer_sbasic_info(const snd_mixer_class_t *class, sm_class_basic_t *info) { WARNX1("stub"); return 0; }
void *snd_mixer_sbasic_get_private(const snd_mixer_class_t *class) { WARNX1("stub"); return NULL; }
void snd_mixer_sbasic_set_private(const snd_mixer_class_t *class, void *private_data) { WARNX1("stub");  }
void snd_mixer_sbasic_set_private_free(const snd_mixer_class_t *class, void (*private_free)(snd_mixer_class_t *class)) { WARNX1("stub");  }
int snd_output_stdio_open(snd_output_t **outputp, const char *file, const char *mode) { WARNX1("stub"); return 0; }
int snd_output_stdio_attach(snd_output_t **outputp, FILE *fp, int _close) { WARNX1("stub"); return 0; }
int snd_output_buffer_open(snd_output_t **outputp) { WARNX1("stub"); return 0; }
size_t snd_output_buffer_string(snd_output_t *output, char **buf) { WARNX1("stub"); return 0; }
int snd_output_close(snd_output_t *output) { WARNX1("stub"); return 0; }
int snd_output_vprintf(snd_output_t *output, const char *format, va_list args) { WARNX1("stub"); return 0; }
int snd_output_puts(snd_output_t *output, const char *str) { WARNX1("stub"); return 0; }
int snd_output_putc(snd_output_t *output, int c) { WARNX1("stub"); return 0; }
int snd_output_flush(snd_output_t *output) { WARNX1("stub"); return 0; }
int snd_pcm_open_lconf(snd_pcm_t **pcm, const char *name, snd_pcm_stream_t stream, int mode, snd_config_t *lconf) { WARNX1("stub"); return 0; }
int snd_pcm_open_fallback(snd_pcm_t **pcm, snd_config_t *root, const char *name, const char *orig_name, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
snd_pcm_type_t snd_pcm_type(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
snd_pcm_stream_t snd_pcm_stream(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
int snd_pcm_poll_descriptors_count(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
int snd_pcm_poll_descriptors(snd_pcm_t *pcm, struct pollfd *pfds, unsigned int space) { WARNX1("stub"); return 0; }
int snd_pcm_poll_descriptors_revents(snd_pcm_t *pcm, struct pollfd *pfds, unsigned int nfds, unsigned short *revents) { WARNX1("stub"); return 0; }
int snd_async_add_pcm_handler(snd_async_handler_t **handler, snd_pcm_t *pcm, snd_async_callback_t callback, void *private_data) { WARNX1("stub"); return 0; }
snd_pcm_t *snd_async_handler_get_pcm(snd_async_handler_t *handler) { WARNX1("stub"); return NULL; }
int snd_pcm_info(snd_pcm_t *pcm, snd_pcm_info_t *info) { WARNX1("stub"); return 0; }
int snd_pcm_hw_free(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params(snd_pcm_t *pcm, snd_pcm_sw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_reset(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
int snd_pcm_status(snd_pcm_t *pcm, snd_pcm_status_t *status) { WARNX1("stub"); return 0; }
int snd_pcm_hwsync(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
int snd_pcm_htimestamp(snd_pcm_t *pcm, snd_pcm_uframes_t *avail, snd_htimestamp_t *tstamp) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_avail(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
int snd_pcm_avail_delay(snd_pcm_t *pcm, snd_pcm_sframes_t *availp, snd_pcm_sframes_t *delayp) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_rewindable(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_rewind(snd_pcm_t *pcm, snd_pcm_uframes_t frames) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_forwardable(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_forward(snd_pcm_t *pcm, snd_pcm_uframes_t frames) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_writen(snd_pcm_t *pcm, void **bufs, snd_pcm_uframes_t size) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_readn(snd_pcm_t *pcm, void **bufs, snd_pcm_uframes_t size) { WARNX1("stub"); return 0; }
int snd_pcm_wait(snd_pcm_t *pcm, int timeout) { WARNX1("stub"); return 0; }
int snd_pcm_link(snd_pcm_t *pcm1, snd_pcm_t *pcm2) { WARNX1("stub"); return 0; }
int snd_pcm_unlink(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
snd_pcm_chmap_query_t **snd_pcm_query_chmaps(snd_pcm_t *pcm) { WARNX1("stub"); return NULL; }
snd_pcm_chmap_query_t **snd_pcm_query_chmaps_from_hw(int card, int dev, int subdev, snd_pcm_stream_t stream) { WARNX1("stub"); return NULL; }
void snd_pcm_free_chmaps(snd_pcm_chmap_query_t **maps) { WARNX1("stub");  }
snd_pcm_chmap_t *snd_pcm_get_chmap(snd_pcm_t *pcm) { WARNX1("stub"); return NULL; }
int snd_pcm_set_chmap(snd_pcm_t *pcm, const snd_pcm_chmap_t *map) { WARNX1("stub"); return 0; }
const char *snd_pcm_chmap_type_name(enum snd_pcm_chmap_type val) { WARNX1("stub"); return NULL; }
const char *snd_pcm_chmap_name(enum snd_pcm_chmap_position val) { WARNX1("stub"); return NULL; }
const char *snd_pcm_chmap_long_name(enum snd_pcm_chmap_position val) { WARNX1("stub"); return NULL; }
int snd_pcm_chmap_print(const snd_pcm_chmap_t *map, size_t maxlen, char *buf) { WARNX1("stub"); return 0; }
unsigned int snd_pcm_chmap_from_string(const char *str) { WARNX1("stub"); return 0; }
snd_pcm_chmap_t *snd_pcm_chmap_parse_string(const char *str) { WARNX1("stub"); return NULL; }
int snd_pcm_recover(snd_pcm_t *pcm, int err, int silent) { WARNX1("stub"); return 0; }
size_t snd_pcm_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_pcm_info_malloc(snd_pcm_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_pcm_info_free(snd_pcm_info_t *obj) { WARNX1("stub");  }
void snd_pcm_info_copy(snd_pcm_info_t *dst, const snd_pcm_info_t *src) { WARNX1("stub");  }
unsigned int snd_pcm_info_get_device(const snd_pcm_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_pcm_info_get_subdevice(const snd_pcm_info_t *obj) { WARNX1("stub"); return 0; }
snd_pcm_stream_t snd_pcm_info_get_stream(const snd_pcm_info_t *obj) { WARNX1("stub"); return 0; }
int snd_pcm_info_get_card(const snd_pcm_info_t *obj) { WARNX1("stub"); return 0; }
const char *snd_pcm_info_get_id(const snd_pcm_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_pcm_info_get_name(const snd_pcm_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_pcm_info_get_subdevice_name(const snd_pcm_info_t *obj) { WARNX1("stub"); return NULL; }
snd_pcm_class_t snd_pcm_info_get_class(const snd_pcm_info_t *obj) { WARNX1("stub"); return 0; }
snd_pcm_subclass_t snd_pcm_info_get_subclass(const snd_pcm_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_pcm_info_get_subdevices_count(const snd_pcm_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_pcm_info_get_subdevices_avail(const snd_pcm_info_t *obj) { WARNX1("stub"); return 0; }
snd_pcm_sync_id_t snd_pcm_info_get_sync(const snd_pcm_info_t *obj) { WARNX1("stub"); return (snd_pcm_sync_id_t){0}; }
void snd_pcm_info_set_device(snd_pcm_info_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_pcm_info_set_subdevice(snd_pcm_info_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_pcm_info_set_stream(snd_pcm_info_t *obj, snd_pcm_stream_t val) { WARNX1("stub");  }
int snd_pcm_hw_params_can_mmap_sample_resolution(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_is_double(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_is_batch(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_is_block_transfer(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_is_monotonic(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_can_overrange(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_can_pause(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_can_resume(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_is_half_duplex(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_is_joint_duplex(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_can_sync_start(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_can_disable_period_wakeup(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_supports_audio_wallclock_ts(const snd_pcm_hw_params_t *params) /* deprecated, use audio_ts_type */ { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_supports_audio_ts_type(const snd_pcm_hw_params_t *params, int type) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_rate_numden(const snd_pcm_hw_params_t *params, unsigned int *rate_num, unsigned int *rate_den) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_sbits(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_fifo_size(const snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_try_explain_failure(snd_pcm_t *pcm, snd_pcm_hw_params_t *fail, snd_pcm_hw_params_t *success, unsigned int depth, snd_output_t *out) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_malloc(snd_pcm_hw_params_t **ptr) { WARNX1("stub"); return 0; }
void snd_pcm_hw_params_free(snd_pcm_hw_params_t *obj) { WARNX1("stub");  }
int snd_pcm_hw_params_get_access(const snd_pcm_hw_params_t *params, snd_pcm_access_t *_access) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_access(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t _access) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_access_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t *_access) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_access_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t *_access) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_access_mask(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_mask_t *mask) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_access_mask(snd_pcm_hw_params_t *params, snd_pcm_access_mask_t *mask) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_format(const snd_pcm_hw_params_t *params, snd_pcm_format_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_format(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_format_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t *format) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_format_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t *format) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_format_mask(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_mask_t *mask) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_subformat(const snd_pcm_hw_params_t *params, snd_pcm_subformat_t *subformat) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_subformat(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_t subformat) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_subformat(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_t subformat) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_subformat_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_t *subformat) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_subformat_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_t *subformat) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_subformat_mask(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_mask_t *mask) { WARNX1("stub"); return 0; }
void snd_pcm_hw_params_get_subformat_mask(snd_pcm_hw_params_t *params, snd_pcm_subformat_mask_t *mask) { WARNX1("stub");  }
int snd_pcm_hw_params_test_channels(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_channels_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_channels_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_channels_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, unsigned int *max) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_channels_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_channels_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_channels_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_rate(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_rate_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_rate_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_rate_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_rate_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_rate_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_rate_resample(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_rate_resample(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_export_buffer(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_export_buffer(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_wakeup(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_period_wakeup(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_period_time(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_period_time_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_period_time_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_period_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_time_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_time_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_time_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_time_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_time_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_time_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_period_size(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_size(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_size_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_size_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_size_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *min, int *mindir, snd_pcm_uframes_t *max, int *maxdir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_size_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_size_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_period_size_integer(snd_pcm_t *pcm, snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_periods_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_periods_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_periods(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_periods(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_periods_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_periods_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_periods_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_periods_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_periods_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_periods_integer(snd_pcm_t *pcm, snd_pcm_hw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_buffer_time(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_buffer_time_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_buffer_time_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_buffer_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_time_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_time_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_time_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_time_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_time_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_time_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_buffer_size(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_size(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_size_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_size_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_size_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *min, snd_pcm_uframes_t *max) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_size_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_buffer_size_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_min_align(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_malloc(snd_pcm_sw_params_t **ptr) { WARNX1("stub"); return 0; }
void snd_pcm_sw_params_free(snd_pcm_sw_params_t *obj) { WARNX1("stub");  }
void snd_pcm_sw_params_copy(snd_pcm_sw_params_t *dst, const snd_pcm_sw_params_t *src) { WARNX1("stub");  }
int snd_pcm_sw_params_get_boundary(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_tstamp_mode(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_tstamp_t val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_tstamp_mode(const snd_pcm_sw_params_t *params, snd_pcm_tstamp_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_tstamp_type(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_tstamp_type_t val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_tstamp_type(const snd_pcm_sw_params_t *params, snd_pcm_tstamp_type_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_avail_min(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_avail_min(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_period_event(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, int val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_period_event(const snd_pcm_sw_params_t *params, int *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_start_threshold(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_start_threshold(const snd_pcm_sw_params_t *paramsm, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_stop_threshold(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_stop_threshold(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_silence_threshold(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_silence_threshold(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_silence_size(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_silence_size(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
size_t snd_pcm_access_mask_sizeof(void) { WARNX1("stub"); return 0; }
int snd_pcm_access_mask_malloc(snd_pcm_access_mask_t **ptr) { WARNX1("stub"); return 0; }
void snd_pcm_access_mask_free(snd_pcm_access_mask_t *obj) { WARNX1("stub");  }
void snd_pcm_access_mask_copy(snd_pcm_access_mask_t *dst, const snd_pcm_access_mask_t *src) { WARNX1("stub");  }
void snd_pcm_access_mask_none(snd_pcm_access_mask_t *mask) { WARNX1("stub");  }
void snd_pcm_access_mask_any(snd_pcm_access_mask_t *mask) { WARNX1("stub");  }
int snd_pcm_access_mask_test(const snd_pcm_access_mask_t *mask, snd_pcm_access_t val) { WARNX1("stub"); return 0; }
int snd_pcm_access_mask_empty(const snd_pcm_access_mask_t *mask) { WARNX1("stub"); return 0; }
void snd_pcm_access_mask_set(snd_pcm_access_mask_t *mask, snd_pcm_access_t val) { WARNX1("stub");  }
void snd_pcm_access_mask_reset(snd_pcm_access_mask_t *mask, snd_pcm_access_t val) { WARNX1("stub");  }
int snd_pcm_format_mask_malloc(snd_pcm_format_mask_t **ptr) { WARNX1("stub"); return 0; }
void snd_pcm_format_mask_free(snd_pcm_format_mask_t *obj) { WARNX1("stub");  }
void snd_pcm_format_mask_copy(snd_pcm_format_mask_t *dst, const snd_pcm_format_mask_t *src) { WARNX1("stub");  }
void snd_pcm_format_mask_none(snd_pcm_format_mask_t *mask) { WARNX1("stub");  }
void snd_pcm_format_mask_any(snd_pcm_format_mask_t *mask) { WARNX1("stub");  }
int snd_pcm_format_mask_empty(const snd_pcm_format_mask_t *mask) { WARNX1("stub"); return 0; }
void snd_pcm_format_mask_set(snd_pcm_format_mask_t *mask, snd_pcm_format_t val) { WARNX1("stub");  }
void snd_pcm_format_mask_reset(snd_pcm_format_mask_t *mask, snd_pcm_format_t val) { WARNX1("stub");  }
size_t snd_pcm_subformat_mask_sizeof(void) { WARNX1("stub"); return 0; }
int snd_pcm_subformat_mask_malloc(snd_pcm_subformat_mask_t **ptr) { WARNX1("stub"); return 0; }
void snd_pcm_subformat_mask_free(snd_pcm_subformat_mask_t *obj) { WARNX1("stub");  }
void snd_pcm_subformat_mask_copy(snd_pcm_subformat_mask_t *dst, const snd_pcm_subformat_mask_t *src) { WARNX1("stub");  }
void snd_pcm_subformat_mask_none(snd_pcm_subformat_mask_t *mask) { WARNX1("stub");  }
void snd_pcm_subformat_mask_any(snd_pcm_subformat_mask_t *mask) { WARNX1("stub");  }
int snd_pcm_subformat_mask_test(const snd_pcm_subformat_mask_t *mask, snd_pcm_subformat_t val) { WARNX1("stub"); return 0; }
int snd_pcm_subformat_mask_empty(const snd_pcm_subformat_mask_t *mask) { WARNX1("stub"); return 0; }
void snd_pcm_subformat_mask_set(snd_pcm_subformat_mask_t *mask, snd_pcm_subformat_t val) { WARNX1("stub");  }
void snd_pcm_subformat_mask_reset(snd_pcm_subformat_mask_t *mask, snd_pcm_subformat_t val) { WARNX1("stub");  }
size_t snd_pcm_status_sizeof(void) { WARNX1("stub"); return 0; }
int snd_pcm_status_malloc(snd_pcm_status_t **ptr) { WARNX1("stub"); return 0; }
void snd_pcm_status_free(snd_pcm_status_t *obj) { WARNX1("stub");  }
void snd_pcm_status_copy(snd_pcm_status_t *dst, const snd_pcm_status_t *src) { WARNX1("stub");  }
snd_pcm_state_t snd_pcm_status_get_state(const snd_pcm_status_t *obj) { WARNX1("stub"); return 0; }
void snd_pcm_status_get_trigger_tstamp(const snd_pcm_status_t *obj, snd_timestamp_t *ptr) { WARNX1("stub");  }
void snd_pcm_status_get_trigger_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr) { WARNX1("stub");  }
void snd_pcm_status_get_tstamp(const snd_pcm_status_t *obj, snd_timestamp_t *ptr) { WARNX1("stub");  }
void snd_pcm_status_get_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr) { WARNX1("stub");  }
void snd_pcm_status_get_audio_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr) { WARNX1("stub");  }
void snd_pcm_status_get_driver_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr) { WARNX1("stub");  }
void snd_pcm_status_get_audio_htstamp_report(const snd_pcm_status_t *obj, snd_pcm_audio_tstamp_report_t *audio_tstamp_report) { WARNX1("stub");  }
void snd_pcm_status_set_audio_htstamp_config(snd_pcm_status_t *obj, snd_pcm_audio_tstamp_config_t *audio_tstamp_config) { WARNX1("stub");  }
snd_pcm_sframes_t snd_pcm_status_get_delay(const snd_pcm_status_t *obj) { WARNX1("stub"); return 0; }
snd_pcm_uframes_t snd_pcm_status_get_avail(const snd_pcm_status_t *obj) { WARNX1("stub"); return 0; }
snd_pcm_uframes_t snd_pcm_status_get_avail_max(const snd_pcm_status_t *obj) { WARNX1("stub"); return 0; }
snd_pcm_uframes_t snd_pcm_status_get_overrange(const snd_pcm_status_t *obj) { WARNX1("stub"); return 0; }
const char *snd_pcm_type_name(snd_pcm_type_t type) { WARNX1("stub"); return NULL; }
const char *snd_pcm_stream_name(const snd_pcm_stream_t stream) { WARNX1("stub"); return NULL; }
const char *snd_pcm_access_name(const snd_pcm_access_t _access) { WARNX1("stub"); return NULL; }
const char *snd_pcm_format_description(const snd_pcm_format_t format) { WARNX1("stub"); return NULL; }
const char *snd_pcm_subformat_name(const snd_pcm_subformat_t subformat) { WARNX1("stub"); return NULL; }
const char *snd_pcm_subformat_description(const snd_pcm_subformat_t subformat) { WARNX1("stub"); return NULL; }
snd_pcm_format_t snd_pcm_format_value(const char* name) { WARNX1("stub"); return 0; }
const char *snd_pcm_tstamp_mode_name(const snd_pcm_tstamp_t mode) { WARNX1("stub"); return NULL; }
const char *snd_pcm_state_name(const snd_pcm_state_t state) { WARNX1("stub"); return NULL; }
int snd_pcm_dump(snd_pcm_t *pcm, snd_output_t *out) { WARNX1("stub"); return 0; }
int snd_pcm_dump_hw_setup(snd_pcm_t *pcm, snd_output_t *out) { WARNX1("stub"); return 0; }
int snd_pcm_dump_sw_setup(snd_pcm_t *pcm, snd_output_t *out) { WARNX1("stub"); return 0; }
int snd_pcm_dump_setup(snd_pcm_t *pcm, snd_output_t *out) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_dump(snd_pcm_hw_params_t *params, snd_output_t *out) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_dump(snd_pcm_sw_params_t *params, snd_output_t *out) { WARNX1("stub"); return 0; }
int snd_pcm_status_dump(snd_pcm_status_t *status, snd_output_t *out) { WARNX1("stub"); return 0; }
int snd_pcm_mmap_begin(snd_pcm_t *pcm, const snd_pcm_channel_area_t **areas, snd_pcm_uframes_t *offset, snd_pcm_uframes_t *frames) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_mmap_commit(snd_pcm_t *pcm, snd_pcm_uframes_t offset, snd_pcm_uframes_t frames) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_mmap_writei(snd_pcm_t *pcm, const void *buffer, snd_pcm_uframes_t size) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_mmap_readi(snd_pcm_t *pcm, void *buffer, snd_pcm_uframes_t size) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_mmap_writen(snd_pcm_t *pcm, void **bufs, snd_pcm_uframes_t size) { WARNX1("stub"); return 0; }
snd_pcm_sframes_t snd_pcm_mmap_readn(snd_pcm_t *pcm, void **bufs, snd_pcm_uframes_t size) { WARNX1("stub"); return 0; }
int snd_pcm_format_signed(snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_format_unsigned(snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_format_linear(snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_format_float(snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_format_little_endian(snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_format_big_endian(snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_format_cpu_endian(snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_format_width(snd_pcm_format_t format)			/* in bits */ { WARNX1("stub"); return 0; }
int snd_pcm_format_physical_width(snd_pcm_format_t format)		/* in bits */ { WARNX1("stub"); return 0; }
snd_pcm_format_t snd_pcm_build_linear_format(int width, int pwidth, int unsignd, int big_endian) { WARNX1("stub"); return 0; }
ssize_t snd_pcm_format_size(snd_pcm_format_t format, size_t samples) { WARNX1("stub"); return 0; }
int snd_pcm_format_set_silence(snd_pcm_format_t format, void *buf, unsigned int samples) { WARNX1("stub"); return 0; }
long snd_pcm_bytes_to_samples(snd_pcm_t *pcm, ssize_t bytes) { WARNX1("stub"); return 0; }
ssize_t snd_pcm_samples_to_bytes(snd_pcm_t *pcm, long samples) { WARNX1("stub"); return 0; }
int snd_pcm_area_silence(const snd_pcm_channel_area_t *dst_channel, snd_pcm_uframes_t dst_offset, unsigned int samples, snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_areas_silence(const snd_pcm_channel_area_t *dst_channels, snd_pcm_uframes_t dst_offset, unsigned int channels, snd_pcm_uframes_t frames, snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_area_copy(const snd_pcm_channel_area_t *dst_channel, snd_pcm_uframes_t dst_offset, const snd_pcm_channel_area_t *src_channel, snd_pcm_uframes_t src_offset, unsigned int samples, snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_areas_copy(const snd_pcm_channel_area_t *dst_channels, snd_pcm_uframes_t dst_offset, const snd_pcm_channel_area_t *src_channels, snd_pcm_uframes_t src_offset, unsigned int channels, snd_pcm_uframes_t frames, snd_pcm_format_t format) { WARNX1("stub"); return 0; }
int snd_pcm_areas_copy_wrap(const snd_pcm_channel_area_t *dst_channels, snd_pcm_uframes_t dst_offset, const snd_pcm_uframes_t dst_size, const snd_pcm_channel_area_t *src_channels, snd_pcm_uframes_t src_offset, const snd_pcm_uframes_t src_size, const unsigned int channels, snd_pcm_uframes_t frames, const snd_pcm_format_t format) { WARNX1("stub"); return 0; }
snd_pcm_t *snd_pcm_hook_get_pcm(snd_pcm_hook_t *hook) { WARNX1("stub"); return NULL; }
void *snd_pcm_hook_get_private(snd_pcm_hook_t *hook) { WARNX1("stub"); return NULL; }
void snd_pcm_hook_set_private(snd_pcm_hook_t *hook, void *private_data) { WARNX1("stub");  }
int snd_pcm_hook_add(snd_pcm_hook_t **hookp, snd_pcm_t *pcm, snd_pcm_hook_type_t type, snd_pcm_hook_func_t func, void *private_data) { WARNX1("stub"); return 0; }
int snd_pcm_hook_remove(snd_pcm_hook_t *hook) { WARNX1("stub"); return 0; }
snd_pcm_uframes_t snd_pcm_meter_get_bufsize(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
unsigned int snd_pcm_meter_get_channels(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
unsigned int snd_pcm_meter_get_rate(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
snd_pcm_uframes_t snd_pcm_meter_get_now(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
snd_pcm_uframes_t snd_pcm_meter_get_boundary(snd_pcm_t *pcm) { WARNX1("stub"); return 0; }
int snd_pcm_meter_add_scope(snd_pcm_t *pcm, snd_pcm_scope_t *scope) { WARNX1("stub"); return 0; }
snd_pcm_scope_t *snd_pcm_meter_search_scope(snd_pcm_t *pcm, const char *name) { WARNX1("stub"); return NULL; }
int snd_pcm_scope_malloc(snd_pcm_scope_t **ptr) { WARNX1("stub"); return 0; }
void snd_pcm_scope_set_ops(snd_pcm_scope_t *scope, const snd_pcm_scope_ops_t *val) { WARNX1("stub");  }
void snd_pcm_scope_set_name(snd_pcm_scope_t *scope, const char *val) { WARNX1("stub");  }
const char *snd_pcm_scope_get_name(snd_pcm_scope_t *scope) { WARNX1("stub"); return NULL; }
void *snd_pcm_scope_get_callback_private(snd_pcm_scope_t *scope) { WARNX1("stub"); return NULL; }
void snd_pcm_scope_set_callback_private(snd_pcm_scope_t *scope, void *val) { WARNX1("stub");  }
int snd_spcm_init(snd_pcm_t *pcm, unsigned int rate, unsigned int channels, snd_pcm_format_t format, snd_pcm_subformat_t subformat, snd_spcm_latency_t latency, snd_pcm_access_t _access, snd_spcm_xrun_type_t xrun_type) { WARNX1("stub"); return 0; }
int snd_spcm_init_duplex(snd_pcm_t *playback_pcm, snd_pcm_t *capture_pcm, unsigned int rate, unsigned int channels, snd_pcm_format_t format, snd_pcm_subformat_t subformat, snd_spcm_latency_t latency, snd_pcm_access_t _access, snd_spcm_xrun_type_t xrun_type, snd_spcm_duplex_type_t duplex_type) { WARNX1("stub"); return 0; }
int snd_spcm_init_get_params(snd_pcm_t *pcm, unsigned int *rate, snd_pcm_uframes_t *buffer_size, snd_pcm_uframes_t *period_size) { WARNX1("stub"); return 0; }
const char *snd_pcm_start_mode_name(snd_pcm_start_t mode) { WARNX1("stub"); return NULL; }
const char *snd_pcm_xrun_mode_name(snd_pcm_xrun_t mode) { WARNX1("stub"); return NULL; }
int snd_pcm_sw_params_set_start_mode(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_start_t val) { WARNX1("stub"); return 0; }
snd_pcm_start_t snd_pcm_sw_params_get_start_mode(const snd_pcm_sw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_xrun_mode(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_xrun_t val) { WARNX1("stub"); return 0; }
snd_pcm_xrun_t snd_pcm_sw_params_get_xrun_mode(const snd_pcm_sw_params_t *params) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_xfer_align(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_xfer_align(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_set_sleep_min(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, unsigned int val) { WARNX1("stub"); return 0; }
int snd_pcm_sw_params_get_sleep_min(const snd_pcm_sw_params_t *params, unsigned int *val) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_tick_time(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_tick_time_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_get_tick_time_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_test_tick_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_tick_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_tick_time_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_tick_time_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_tick_time_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_tick_time_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_tick_time_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_hw_params_set_tick_time_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) { WARNX1("stub"); return 0; }
int snd_pcm_parse_control_id(snd_config_t *conf, snd_ctl_elem_id_t *ctl_id, int *cardp, int *cchannelsp, int *hwctlp) { WARNX1("stub"); return 0; }
int snd_pcm_extplug_create(snd_pcm_extplug_t *ext, const char *name, snd_config_t *root, snd_config_t *slave_conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_extplug_delete(snd_pcm_extplug_t *ext) { WARNX1("stub"); return 0; }
void snd_pcm_extplug_params_reset(snd_pcm_extplug_t *ext) { WARNX1("stub");  }
int snd_pcm_extplug_set_param_list(snd_pcm_extplug_t *extplug, int type, unsigned int num_list, const unsigned int *list) { WARNX1("stub"); return 0; }
int snd_pcm_extplug_set_param_minmax(snd_pcm_extplug_t *extplug, int type, unsigned int min, unsigned int max) { WARNX1("stub"); return 0; }
int snd_pcm_extplug_set_slave_param_list(snd_pcm_extplug_t *extplug, int type, unsigned int num_list, const unsigned int *list) { WARNX1("stub"); return 0; }
int snd_pcm_extplug_set_slave_param_minmax(snd_pcm_extplug_t *extplug, int type, unsigned int min, unsigned int max) { WARNX1("stub"); return 0; }
int snd_pcm_ioplug_create(snd_pcm_ioplug_t *io, const char *name, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_ioplug_delete(snd_pcm_ioplug_t *io) { WARNX1("stub"); return 0; }
int snd_pcm_ioplug_reinit_status(snd_pcm_ioplug_t *ioplug) { WARNX1("stub"); return 0; }
const snd_pcm_channel_area_t *snd_pcm_ioplug_mmap_areas(snd_pcm_ioplug_t *ioplug) { WARNX1("stub"); return NULL; }
void snd_pcm_ioplug_params_reset(snd_pcm_ioplug_t *io) { WARNX1("stub");  }
int snd_pcm_ioplug_set_param_minmax(snd_pcm_ioplug_t *io, int type, unsigned int min, unsigned int max) { WARNX1("stub"); return 0; }
int snd_pcm_ioplug_set_param_list(snd_pcm_ioplug_t *io, int type, unsigned int num_list, const unsigned int *list) { WARNX1("stub"); return 0; }
int snd_pcm_ioplug_set_state(snd_pcm_ioplug_t *ioplug, snd_pcm_state_t state) { WARNX1("stub"); return 0; }
snd_pcm_uframes_t snd_pcm_ioplug_avail(const snd_pcm_ioplug_t * const ioplug, const snd_pcm_uframes_t hw_ptr, const snd_pcm_uframes_t appl_ptr) { WARNX1("stub"); return 0; }
snd_pcm_uframes_t snd_pcm_ioplug_hw_avail(const snd_pcm_ioplug_t * const ioplug, const snd_pcm_uframes_t hw_ptr, const snd_pcm_uframes_t appl_ptr) { WARNX1("stub"); return 0; }
int snd_pcm_hw_open(snd_pcm_t **pcmp, const char *name, int card, int device, int subdevice, snd_pcm_stream_t stream, int mode, int mmap_emulation, int sync_ptr_ioctl) { WARNX1("stub"); return 0; }
int _snd_pcm_hw_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root ATTRIBUTE_UNUSED, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_copy_open(snd_pcm_t **pcmp, const char *name, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_copy_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_linear_open(snd_pcm_t **pcmp, const char *name, snd_pcm_format_t sformat, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_linear_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_lfloat_open(snd_pcm_t **pcmp, const char *name, snd_pcm_format_t sformat, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_lfloat_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_mulaw_open(snd_pcm_t **pcmp, const char *name, snd_pcm_format_t sformat, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_mulaw_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_alaw_open(snd_pcm_t **pcmp, const char *name, snd_pcm_format_t sformat, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_alaw_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_adpcm_open(snd_pcm_t **pcmp, const char *name, snd_pcm_format_t sformat, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_adpcm_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_route_load_ttable(snd_config_t *tt, snd_pcm_route_ttable_entry_t *ttable, unsigned int tt_csize, unsigned int tt_ssize, unsigned int *tt_cused, unsigned int *tt_sused, int schannels) { WARNX1("stub"); return 0; }
int snd_pcm_route_determine_ttable(snd_config_t *tt, unsigned int *tt_csize, unsigned int *tt_ssize) { WARNX1("stub"); return 0; }
int snd_pcm_route_open(snd_pcm_t **pcmp, const char *name, snd_pcm_format_t sformat, int schannels, snd_pcm_route_ttable_entry_t *ttable, unsigned int tt_ssize, unsigned int tt_cused, unsigned int tt_sused, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_route_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_rate_open(snd_pcm_t **pcmp, const char *name, snd_pcm_format_t sformat, unsigned int srate, const snd_config_t *converter, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_rate_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_hooks_open(snd_pcm_t **pcmp, const char *name, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_hooks_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_ladspa_open(snd_pcm_t **pcmp, const char *name, const char *ladspa_path, unsigned int channels, snd_config_t *ladspa_pplugins, snd_config_t *ladspa_cplugins, snd_pcm_t *slave, int close_slave) { WARNX1("stub"); return 0; }
int _snd_pcm_ladspa_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_pcm_jack_open(snd_pcm_t **pcmp, const char *name, snd_config_t *playback_conf, snd_config_t *capture_conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int _snd_pcm_jack_open(snd_pcm_t **pcmp, const char *name, snd_config_t *root, snd_config_t *conf, snd_pcm_stream_t stream, int mode) { WARNX1("stub"); return 0; }
int snd_rawmidi_open(snd_rawmidi_t **in_rmidi, snd_rawmidi_t **out_rmidi, const char *name, int mode) { WARNX1("stub"); return 0; }
int snd_rawmidi_open_lconf(snd_rawmidi_t **in_rmidi, snd_rawmidi_t **out_rmidi, const char *name, int mode, snd_config_t *lconf) { WARNX1("stub"); return 0; }
int snd_rawmidi_close(snd_rawmidi_t *rmidi) { WARNX1("stub"); return 0; }
int snd_rawmidi_poll_descriptors_count(snd_rawmidi_t *rmidi) { WARNX1("stub"); return 0; }
int snd_rawmidi_poll_descriptors(snd_rawmidi_t *rmidi, struct pollfd *pfds, unsigned int space) { WARNX1("stub"); return 0; }
int snd_rawmidi_poll_descriptors_revents(snd_rawmidi_t *rawmidi, struct pollfd *pfds, unsigned int nfds, unsigned short *revent) { WARNX1("stub"); return 0; }
int snd_rawmidi_nonblock(snd_rawmidi_t *rmidi, int nonblock) { WARNX1("stub"); return 0; }
size_t snd_rawmidi_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_rawmidi_info_malloc(snd_rawmidi_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_rawmidi_info_free(snd_rawmidi_info_t *obj) { WARNX1("stub");  }
void snd_rawmidi_info_copy(snd_rawmidi_info_t *dst, const snd_rawmidi_info_t *src) { WARNX1("stub");  }
unsigned int snd_rawmidi_info_get_device(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_rawmidi_info_get_subdevice(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return 0; }
snd_rawmidi_stream_t snd_rawmidi_info_get_stream(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return 0; }
int snd_rawmidi_info_get_card(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_rawmidi_info_get_flags(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return 0; }
const char *snd_rawmidi_info_get_id(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_rawmidi_info_get_name(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return NULL; }
const char *snd_rawmidi_info_get_subdevice_name(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_rawmidi_info_get_subdevices_count(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_rawmidi_info_get_subdevices_avail(const snd_rawmidi_info_t *obj) { WARNX1("stub"); return 0; }
void snd_rawmidi_info_set_device(snd_rawmidi_info_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_rawmidi_info_set_subdevice(snd_rawmidi_info_t *obj, unsigned int val) { WARNX1("stub");  }
void snd_rawmidi_info_set_stream(snd_rawmidi_info_t *obj, snd_rawmidi_stream_t val) { WARNX1("stub");  }
int snd_rawmidi_info(snd_rawmidi_t *rmidi, snd_rawmidi_info_t * info) { WARNX1("stub"); return 0; }
size_t snd_rawmidi_params_sizeof(void) { WARNX1("stub"); return 0; }
int snd_rawmidi_params_malloc(snd_rawmidi_params_t **ptr) { WARNX1("stub"); return 0; }
void snd_rawmidi_params_free(snd_rawmidi_params_t *obj) { WARNX1("stub");  }
void snd_rawmidi_params_copy(snd_rawmidi_params_t *dst, const snd_rawmidi_params_t *src) { WARNX1("stub");  }
int snd_rawmidi_params_set_buffer_size(snd_rawmidi_t *rmidi, snd_rawmidi_params_t *params, size_t val) { WARNX1("stub"); return 0; }
size_t snd_rawmidi_params_get_buffer_size(const snd_rawmidi_params_t *params) { WARNX1("stub"); return 0; }
int snd_rawmidi_params_set_avail_min(snd_rawmidi_t *rmidi, snd_rawmidi_params_t *params, size_t val) { WARNX1("stub"); return 0; }
size_t snd_rawmidi_params_get_avail_min(const snd_rawmidi_params_t *params) { WARNX1("stub"); return 0; }
int snd_rawmidi_params_set_no_active_sensing(snd_rawmidi_t *rmidi, snd_rawmidi_params_t *params, int val) { WARNX1("stub"); return 0; }
int snd_rawmidi_params_get_no_active_sensing(const snd_rawmidi_params_t *params) { WARNX1("stub"); return 0; }
int snd_rawmidi_params(snd_rawmidi_t *rmidi, snd_rawmidi_params_t * params) { WARNX1("stub"); return 0; }
int snd_rawmidi_params_current(snd_rawmidi_t *rmidi, snd_rawmidi_params_t *params) { WARNX1("stub"); return 0; }
size_t snd_rawmidi_status_sizeof(void) { WARNX1("stub"); return 0; }
int snd_rawmidi_status_malloc(snd_rawmidi_status_t **ptr) { WARNX1("stub"); return 0; }
void snd_rawmidi_status_free(snd_rawmidi_status_t *obj) { WARNX1("stub");  }
void snd_rawmidi_status_copy(snd_rawmidi_status_t *dst, const snd_rawmidi_status_t *src) { WARNX1("stub");  }
void snd_rawmidi_status_get_tstamp(const snd_rawmidi_status_t *obj, snd_htimestamp_t *ptr) { WARNX1("stub");  }
size_t snd_rawmidi_status_get_avail(const snd_rawmidi_status_t *obj) { WARNX1("stub"); return 0; }
size_t snd_rawmidi_status_get_xruns(const snd_rawmidi_status_t *obj) { WARNX1("stub"); return 0; }
int snd_rawmidi_status(snd_rawmidi_t *rmidi, snd_rawmidi_status_t * status) { WARNX1("stub"); return 0; }
int snd_rawmidi_drain(snd_rawmidi_t *rmidi) { WARNX1("stub"); return 0; }
int snd_rawmidi_drop(snd_rawmidi_t *rmidi) { WARNX1("stub"); return 0; }
ssize_t snd_rawmidi_write(snd_rawmidi_t *rmidi, const void *buffer, size_t size) { WARNX1("stub"); return 0; }
ssize_t snd_rawmidi_read(snd_rawmidi_t *rmidi, void *buffer, size_t size) { WARNX1("stub"); return 0; }
const char *snd_rawmidi_name(snd_rawmidi_t *rmidi) { WARNX1("stub"); return NULL; }
snd_rawmidi_type_t snd_rawmidi_type(snd_rawmidi_t *rmidi) { WARNX1("stub"); return 0; }
snd_rawmidi_stream_t snd_rawmidi_stream(snd_rawmidi_t *rawmidi) { WARNX1("stub"); return 0; }
int snd_seq_open(snd_seq_t **handle, const char *name, int streams, int mode) { WARNX1("stub"); return 0; }
int snd_seq_open_lconf(snd_seq_t **handle, const char *name, int streams, int mode, snd_config_t *lconf) { WARNX1("stub"); return 0; }
const char *snd_seq_name(snd_seq_t *seq) { WARNX1("stub"); return NULL; }
snd_seq_type_t snd_seq_type(snd_seq_t *seq) { WARNX1("stub"); return 0; }
int snd_seq_close(snd_seq_t *handle) { WARNX1("stub"); return 0; }
int snd_seq_poll_descriptors_count(snd_seq_t *handle, short events) { WARNX1("stub"); return 0; }
int snd_seq_poll_descriptors(snd_seq_t *handle, struct pollfd *pfds, unsigned int space, short events) { WARNX1("stub"); return 0; }
int snd_seq_poll_descriptors_revents(snd_seq_t *seq, struct pollfd *pfds, unsigned int nfds, unsigned short *revents) { WARNX1("stub"); return 0; }
int snd_seq_nonblock(snd_seq_t *handle, int nonblock) { WARNX1("stub"); return 0; }
int snd_seq_client_id(snd_seq_t *handle) { WARNX1("stub"); return 0; }
size_t snd_seq_get_output_buffer_size(snd_seq_t *handle) { WARNX1("stub"); return 0; }
size_t snd_seq_get_input_buffer_size(snd_seq_t *handle) { WARNX1("stub"); return 0; }
int snd_seq_set_output_buffer_size(snd_seq_t *handle, size_t size) { WARNX1("stub"); return 0; }
int snd_seq_set_input_buffer_size(snd_seq_t *handle, size_t size) { WARNX1("stub"); return 0; }
size_t snd_seq_system_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_system_info_malloc(snd_seq_system_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_system_info_free(snd_seq_system_info_t *ptr) { WARNX1("stub");  }
void snd_seq_system_info_copy(snd_seq_system_info_t *dst, const snd_seq_system_info_t *src) { WARNX1("stub");  }
int snd_seq_system_info_get_queues(const snd_seq_system_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_system_info_get_clients(const snd_seq_system_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_system_info_get_ports(const snd_seq_system_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_system_info_get_channels(const snd_seq_system_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_system_info_get_cur_clients(const snd_seq_system_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_system_info_get_cur_queues(const snd_seq_system_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_system_info(snd_seq_t *handle, snd_seq_system_info_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_client_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_client_info_malloc(snd_seq_client_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_client_info_free(snd_seq_client_info_t *ptr) { WARNX1("stub");  }
void snd_seq_client_info_copy(snd_seq_client_info_t *dst, const snd_seq_client_info_t *src) { WARNX1("stub");  }
int snd_seq_client_info_get_client(const snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
snd_seq_client_type_t snd_seq_client_info_get_type(const snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
const char *snd_seq_client_info_get_name(snd_seq_client_info_t *info) { WARNX1("stub"); return NULL; }
int snd_seq_client_info_get_broadcast_filter(const snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_client_info_get_error_bounce(const snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_client_info_get_card(const snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_client_info_get_pid(const snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
const unsigned char *snd_seq_client_info_get_event_filter(const snd_seq_client_info_t *info) { WARNX1("stub"); return NULL; }
int snd_seq_client_info_get_num_ports(const snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_client_info_get_event_lost(const snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
void snd_seq_client_info_set_client(snd_seq_client_info_t *info, int client) { WARNX1("stub");  }
void snd_seq_client_info_set_name(snd_seq_client_info_t *info, const char *name) { WARNX1("stub");  }
void snd_seq_client_info_set_broadcast_filter(snd_seq_client_info_t *info, int val) { WARNX1("stub");  }
void snd_seq_client_info_set_error_bounce(snd_seq_client_info_t *info, int val) { WARNX1("stub");  }
void snd_seq_client_info_set_event_filter(snd_seq_client_info_t *info, unsigned char *filter) { WARNX1("stub");  }
void snd_seq_client_info_event_filter_clear(snd_seq_client_info_t *info) { WARNX1("stub");  }
void snd_seq_client_info_event_filter_add(snd_seq_client_info_t *info, int event_type) { WARNX1("stub");  }
void snd_seq_client_info_event_filter_del(snd_seq_client_info_t *info, int event_type) { WARNX1("stub");  }
int snd_seq_client_info_event_filter_check(snd_seq_client_info_t *info, int event_type) { WARNX1("stub"); return 0; }
int snd_seq_get_client_info(snd_seq_t *handle, snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_get_any_client_info(snd_seq_t *handle, int client, snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_set_client_info(snd_seq_t *handle, snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_next_client(snd_seq_t *handle, snd_seq_client_info_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_client_pool_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_client_pool_malloc(snd_seq_client_pool_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_client_pool_free(snd_seq_client_pool_t *ptr) { WARNX1("stub");  }
void snd_seq_client_pool_copy(snd_seq_client_pool_t *dst, const snd_seq_client_pool_t *src) { WARNX1("stub");  }
int snd_seq_client_pool_get_client(const snd_seq_client_pool_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_client_pool_get_output_pool(const snd_seq_client_pool_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_client_pool_get_input_pool(const snd_seq_client_pool_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_client_pool_get_output_room(const snd_seq_client_pool_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_client_pool_get_output_free(const snd_seq_client_pool_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_client_pool_get_input_free(const snd_seq_client_pool_t *info) { WARNX1("stub"); return 0; }
void snd_seq_client_pool_set_output_pool(snd_seq_client_pool_t *info, size_t size) { WARNX1("stub");  }
void snd_seq_client_pool_set_input_pool(snd_seq_client_pool_t *info, size_t size) { WARNX1("stub");  }
void snd_seq_client_pool_set_output_room(snd_seq_client_pool_t *info, size_t size) { WARNX1("stub");  }
int snd_seq_get_client_pool(snd_seq_t *handle, snd_seq_client_pool_t *info) { WARNX1("stub"); return 0; }
int snd_seq_set_client_pool(snd_seq_t *handle, snd_seq_client_pool_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_port_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_port_info_malloc(snd_seq_port_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_port_info_free(snd_seq_port_info_t *ptr) { WARNX1("stub");  }
void snd_seq_port_info_copy(snd_seq_port_info_t *dst, const snd_seq_port_info_t *src) { WARNX1("stub");  }
int snd_seq_port_info_get_client(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_port(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
const snd_seq_addr_t *snd_seq_port_info_get_addr(const snd_seq_port_info_t *info) { WARNX1("stub"); return NULL; }
const char *snd_seq_port_info_get_name(const snd_seq_port_info_t *info) { WARNX1("stub"); return NULL; }
unsigned int snd_seq_port_info_get_capability(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
unsigned int snd_seq_port_info_get_type(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_midi_channels(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_midi_voices(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_synth_voices(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_read_use(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_write_use(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_port_specified(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_timestamping(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_timestamp_real(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_info_get_timestamp_queue(const snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
void snd_seq_port_info_set_client(snd_seq_port_info_t *info, int client) { WARNX1("stub");  }
void snd_seq_port_info_set_port(snd_seq_port_info_t *info, int port) { WARNX1("stub");  }
void snd_seq_port_info_set_addr(snd_seq_port_info_t *info, const snd_seq_addr_t *addr) { WARNX1("stub");  }
void snd_seq_port_info_set_name(snd_seq_port_info_t *info, const char *name) { WARNX1("stub");  }
void snd_seq_port_info_set_capability(snd_seq_port_info_t *info, unsigned int capability) { WARNX1("stub");  }
void snd_seq_port_info_set_type(snd_seq_port_info_t *info, unsigned int type) { WARNX1("stub");  }
void snd_seq_port_info_set_midi_channels(snd_seq_port_info_t *info, int channels) { WARNX1("stub");  }
void snd_seq_port_info_set_midi_voices(snd_seq_port_info_t *info, int voices) { WARNX1("stub");  }
void snd_seq_port_info_set_synth_voices(snd_seq_port_info_t *info, int voices) { WARNX1("stub");  }
void snd_seq_port_info_set_port_specified(snd_seq_port_info_t *info, int val) { WARNX1("stub");  }
void snd_seq_port_info_set_timestamping(snd_seq_port_info_t *info, int enable) { WARNX1("stub");  }
void snd_seq_port_info_set_timestamp_real(snd_seq_port_info_t *info, int realtime) { WARNX1("stub");  }
void snd_seq_port_info_set_timestamp_queue(snd_seq_port_info_t *info, int queue) { WARNX1("stub");  }
int snd_seq_create_port(snd_seq_t *handle, snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_delete_port(snd_seq_t *handle, int port) { WARNX1("stub"); return 0; }
int snd_seq_get_port_info(snd_seq_t *handle, int port, snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_get_any_port_info(snd_seq_t *handle, int client, int port, snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_set_port_info(snd_seq_t *handle, int port, snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_next_port(snd_seq_t *handle, snd_seq_port_info_t *info) { WARNX1("stub"); return 0; }
size_t snd_seq_port_subscribe_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_port_subscribe_malloc(snd_seq_port_subscribe_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_port_subscribe_free(snd_seq_port_subscribe_t *ptr) { WARNX1("stub");  }
void snd_seq_port_subscribe_copy(snd_seq_port_subscribe_t *dst, const snd_seq_port_subscribe_t *src) { WARNX1("stub");  }
const snd_seq_addr_t *snd_seq_port_subscribe_get_sender(const snd_seq_port_subscribe_t *info) { WARNX1("stub"); return NULL; }
const snd_seq_addr_t *snd_seq_port_subscribe_get_dest(const snd_seq_port_subscribe_t *info) { WARNX1("stub"); return NULL; }
int snd_seq_port_subscribe_get_queue(const snd_seq_port_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_subscribe_get_exclusive(const snd_seq_port_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_subscribe_get_time_update(const snd_seq_port_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_port_subscribe_get_time_real(const snd_seq_port_subscribe_t *info) { WARNX1("stub"); return 0; }
void snd_seq_port_subscribe_set_sender(snd_seq_port_subscribe_t *info, const snd_seq_addr_t *addr) { WARNX1("stub");  }
void snd_seq_port_subscribe_set_dest(snd_seq_port_subscribe_t *info, const snd_seq_addr_t *addr) { WARNX1("stub");  }
void snd_seq_port_subscribe_set_queue(snd_seq_port_subscribe_t *info, int q) { WARNX1("stub");  }
void snd_seq_port_subscribe_set_exclusive(snd_seq_port_subscribe_t *info, int val) { WARNX1("stub");  }
void snd_seq_port_subscribe_set_time_update(snd_seq_port_subscribe_t *info, int val) { WARNX1("stub");  }
void snd_seq_port_subscribe_set_time_real(snd_seq_port_subscribe_t *info, int val) { WARNX1("stub");  }
int snd_seq_get_port_subscription(snd_seq_t *handle, snd_seq_port_subscribe_t *sub) { WARNX1("stub"); return 0; }
int snd_seq_subscribe_port(snd_seq_t *handle, snd_seq_port_subscribe_t *sub) { WARNX1("stub"); return 0; }
int snd_seq_unsubscribe_port(snd_seq_t *handle, snd_seq_port_subscribe_t *sub) { WARNX1("stub"); return 0; }
size_t snd_seq_query_subscribe_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_query_subscribe_malloc(snd_seq_query_subscribe_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_query_subscribe_free(snd_seq_query_subscribe_t *ptr) { WARNX1("stub");  }
void snd_seq_query_subscribe_copy(snd_seq_query_subscribe_t *dst, const snd_seq_query_subscribe_t *src) { WARNX1("stub");  }
int snd_seq_query_subscribe_get_client(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_subscribe_get_port(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
const snd_seq_addr_t *snd_seq_query_subscribe_get_root(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return NULL; }
snd_seq_query_subs_type_t snd_seq_query_subscribe_get_type(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_subscribe_get_index(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_subscribe_get_num_subs(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
const snd_seq_addr_t *snd_seq_query_subscribe_get_addr(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return NULL; }
int snd_seq_query_subscribe_get_queue(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_subscribe_get_exclusive(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_subscribe_get_time_update(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_subscribe_get_time_real(const snd_seq_query_subscribe_t *info) { WARNX1("stub"); return 0; }
void snd_seq_query_subscribe_set_client(snd_seq_query_subscribe_t *info, int client) { WARNX1("stub");  }
void snd_seq_query_subscribe_set_port(snd_seq_query_subscribe_t *info, int port) { WARNX1("stub");  }
void snd_seq_query_subscribe_set_root(snd_seq_query_subscribe_t *info, const snd_seq_addr_t *addr) { WARNX1("stub");  }
void snd_seq_query_subscribe_set_type(snd_seq_query_subscribe_t *info, snd_seq_query_subs_type_t type) { WARNX1("stub");  }
void snd_seq_query_subscribe_set_index(snd_seq_query_subscribe_t *info, int _index) { WARNX1("stub");  }
int snd_seq_query_port_subscribers(snd_seq_t *seq, snd_seq_query_subscribe_t * subs) { WARNX1("stub"); return 0; }
size_t snd_seq_queue_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_queue_info_malloc(snd_seq_queue_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_queue_info_free(snd_seq_queue_info_t *ptr) { WARNX1("stub");  }
void snd_seq_queue_info_copy(snd_seq_queue_info_t *dst, const snd_seq_queue_info_t *src) { WARNX1("stub");  }
int snd_seq_queue_info_get_queue(const snd_seq_queue_info_t *info) { WARNX1("stub"); return 0; }
const char *snd_seq_queue_info_get_name(const snd_seq_queue_info_t *info) { WARNX1("stub"); return NULL; }
int snd_seq_queue_info_get_owner(const snd_seq_queue_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_queue_info_get_locked(const snd_seq_queue_info_t *info) { WARNX1("stub"); return 0; }
unsigned int snd_seq_queue_info_get_flags(const snd_seq_queue_info_t *info) { WARNX1("stub"); return 0; }
void snd_seq_queue_info_set_name(snd_seq_queue_info_t *info, const char *name) { WARNX1("stub");  }
void snd_seq_queue_info_set_owner(snd_seq_queue_info_t *info, int owner) { WARNX1("stub");  }
void snd_seq_queue_info_set_locked(snd_seq_queue_info_t *info, int locked) { WARNX1("stub");  }
void snd_seq_queue_info_set_flags(snd_seq_queue_info_t *info, unsigned int flags) { WARNX1("stub");  }
int snd_seq_create_queue(snd_seq_t *seq, snd_seq_queue_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_alloc_named_queue(snd_seq_t *seq, const char *name) { WARNX1("stub"); return 0; }
int snd_seq_alloc_queue(snd_seq_t *handle) { WARNX1("stub"); return 0; }
int snd_seq_free_queue(snd_seq_t *handle, int q) { WARNX1("stub"); return 0; }
int snd_seq_get_queue_info(snd_seq_t *seq, int q, snd_seq_queue_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_set_queue_info(snd_seq_t *seq, int q, snd_seq_queue_info_t *info) { WARNX1("stub"); return 0; }
int snd_seq_query_named_queue(snd_seq_t *seq, const char *name) { WARNX1("stub"); return 0; }
int snd_seq_get_queue_usage(snd_seq_t *handle, int q) { WARNX1("stub"); return 0; }
int snd_seq_set_queue_usage(snd_seq_t *handle, int q, int used) { WARNX1("stub"); return 0; }
size_t snd_seq_queue_status_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_queue_status_malloc(snd_seq_queue_status_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_queue_status_free(snd_seq_queue_status_t *ptr) { WARNX1("stub");  }
void snd_seq_queue_status_copy(snd_seq_queue_status_t *dst, const snd_seq_queue_status_t *src) { WARNX1("stub");  }
int snd_seq_queue_status_get_queue(const snd_seq_queue_status_t *info) { WARNX1("stub"); return 0; }
int snd_seq_queue_status_get_events(const snd_seq_queue_status_t *info) { WARNX1("stub"); return 0; }
snd_seq_tick_time_t snd_seq_queue_status_get_tick_time(const snd_seq_queue_status_t *info) { WARNX1("stub"); return 0; }
const snd_seq_real_time_t *snd_seq_queue_status_get_real_time(const snd_seq_queue_status_t *info) { WARNX1("stub"); return NULL; }
unsigned int snd_seq_queue_status_get_status(const snd_seq_queue_status_t *info) { WARNX1("stub"); return 0; }
int snd_seq_get_queue_status(snd_seq_t *handle, int q, snd_seq_queue_status_t *status) { WARNX1("stub"); return 0; }
size_t snd_seq_queue_tempo_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_queue_tempo_malloc(snd_seq_queue_tempo_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_queue_tempo_free(snd_seq_queue_tempo_t *ptr) { WARNX1("stub");  }
void snd_seq_queue_tempo_copy(snd_seq_queue_tempo_t *dst, const snd_seq_queue_tempo_t *src) { WARNX1("stub");  }
int snd_seq_queue_tempo_get_queue(const snd_seq_queue_tempo_t *info) { WARNX1("stub"); return 0; }
unsigned int snd_seq_queue_tempo_get_tempo(const snd_seq_queue_tempo_t *info) { WARNX1("stub"); return 0; }
int snd_seq_queue_tempo_get_ppq(const snd_seq_queue_tempo_t *info) { WARNX1("stub"); return 0; }
unsigned int snd_seq_queue_tempo_get_skew(const snd_seq_queue_tempo_t *info) { WARNX1("stub"); return 0; }
unsigned int snd_seq_queue_tempo_get_skew_base(const snd_seq_queue_tempo_t *info) { WARNX1("stub"); return 0; }
void snd_seq_queue_tempo_set_tempo(snd_seq_queue_tempo_t *info, unsigned int tempo) { WARNX1("stub");  }
void snd_seq_queue_tempo_set_ppq(snd_seq_queue_tempo_t *info, int ppq) { WARNX1("stub");  }
void snd_seq_queue_tempo_set_skew(snd_seq_queue_tempo_t *info, unsigned int skew) { WARNX1("stub");  }
void snd_seq_queue_tempo_set_skew_base(snd_seq_queue_tempo_t *info, unsigned int base) { WARNX1("stub");  }
int snd_seq_get_queue_tempo(snd_seq_t *handle, int q, snd_seq_queue_tempo_t *tempo) { WARNX1("stub"); return 0; }
int snd_seq_set_queue_tempo(snd_seq_t *handle, int q, snd_seq_queue_tempo_t *tempo) { WARNX1("stub"); return 0; }
size_t snd_seq_queue_timer_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_queue_timer_malloc(snd_seq_queue_timer_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_queue_timer_free(snd_seq_queue_timer_t *ptr) { WARNX1("stub");  }
void snd_seq_queue_timer_copy(snd_seq_queue_timer_t *dst, const snd_seq_queue_timer_t *src) { WARNX1("stub");  }
int snd_seq_queue_timer_get_queue(const snd_seq_queue_timer_t *info) { WARNX1("stub"); return 0; }
snd_seq_queue_timer_type_t snd_seq_queue_timer_get_type(const snd_seq_queue_timer_t *info) { WARNX1("stub"); return 0; }
const snd_timer_id_t *snd_seq_queue_timer_get_id(const snd_seq_queue_timer_t *info) { WARNX1("stub"); return NULL; }
unsigned int snd_seq_queue_timer_get_resolution(const snd_seq_queue_timer_t *info) { WARNX1("stub"); return 0; }
void snd_seq_queue_timer_set_type(snd_seq_queue_timer_t *info, snd_seq_queue_timer_type_t type) { WARNX1("stub");  }
void snd_seq_queue_timer_set_id(snd_seq_queue_timer_t *info, const snd_timer_id_t *id) { WARNX1("stub");  }
void snd_seq_queue_timer_set_resolution(snd_seq_queue_timer_t *info, unsigned int resolution) { WARNX1("stub");  }
int snd_seq_get_queue_timer(snd_seq_t *handle, int q, snd_seq_queue_timer_t *timer) { WARNX1("stub"); return 0; }
int snd_seq_set_queue_timer(snd_seq_t *handle, int q, snd_seq_queue_timer_t *timer) { WARNX1("stub"); return 0; }
int snd_seq_free_event(snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
ssize_t snd_seq_event_length(snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
int snd_seq_event_output(snd_seq_t *handle, snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
int snd_seq_event_output_buffer(snd_seq_t *handle, snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
int snd_seq_event_output_direct(snd_seq_t *handle, snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
int snd_seq_event_input(snd_seq_t *handle, snd_seq_event_t **ev) { WARNX1("stub"); return 0; }
int snd_seq_event_input_pending(snd_seq_t *seq, int fetch_sequencer) { WARNX1("stub"); return 0; }
int snd_seq_drain_output(snd_seq_t *handle) { WARNX1("stub"); return 0; }
int snd_seq_event_output_pending(snd_seq_t *seq) { WARNX1("stub"); return 0; }
int snd_seq_extract_output(snd_seq_t *handle, snd_seq_event_t **ev) { WARNX1("stub"); return 0; }
int snd_seq_drop_output(snd_seq_t *handle) { WARNX1("stub"); return 0; }
int snd_seq_drop_output_buffer(snd_seq_t *handle) { WARNX1("stub"); return 0; }
int snd_seq_drop_input(snd_seq_t *handle) { WARNX1("stub"); return 0; }
int snd_seq_drop_input_buffer(snd_seq_t *handle) { WARNX1("stub"); return 0; }
size_t snd_seq_remove_events_sizeof(void) { WARNX1("stub"); return 0; }
int snd_seq_remove_events_malloc(snd_seq_remove_events_t **ptr) { WARNX1("stub"); return 0; }
void snd_seq_remove_events_free(snd_seq_remove_events_t *ptr) { WARNX1("stub");  }
void snd_seq_remove_events_copy(snd_seq_remove_events_t *dst, const snd_seq_remove_events_t *src) { WARNX1("stub");  }
unsigned int snd_seq_remove_events_get_condition(const snd_seq_remove_events_t *info) { WARNX1("stub"); return 0; }
int snd_seq_remove_events_get_queue(const snd_seq_remove_events_t *info) { WARNX1("stub"); return 0; }
const snd_seq_timestamp_t *snd_seq_remove_events_get_time(const snd_seq_remove_events_t *info) { WARNX1("stub"); return NULL; }
const snd_seq_addr_t *snd_seq_remove_events_get_dest(const snd_seq_remove_events_t *info) { WARNX1("stub"); return NULL; }
int snd_seq_remove_events_get_channel(const snd_seq_remove_events_t *info) { WARNX1("stub"); return 0; }
int snd_seq_remove_events_get_event_type(const snd_seq_remove_events_t *info) { WARNX1("stub"); return 0; }
int snd_seq_remove_events_get_tag(const snd_seq_remove_events_t *info) { WARNX1("stub"); return 0; }
void snd_seq_remove_events_set_condition(snd_seq_remove_events_t *info, unsigned int flags) { WARNX1("stub");  }
void snd_seq_remove_events_set_queue(snd_seq_remove_events_t *info, int queue) { WARNX1("stub");  }
void snd_seq_remove_events_set_time(snd_seq_remove_events_t *info, const snd_seq_timestamp_t *time) { WARNX1("stub");  }
void snd_seq_remove_events_set_dest(snd_seq_remove_events_t *info, const snd_seq_addr_t *addr) { WARNX1("stub");  }
void snd_seq_remove_events_set_channel(snd_seq_remove_events_t *info, int channel) { WARNX1("stub");  }
void snd_seq_remove_events_set_event_type(snd_seq_remove_events_t *info, int type) { WARNX1("stub");  }
void snd_seq_remove_events_set_tag(snd_seq_remove_events_t *info, int tag) { WARNX1("stub");  }
int snd_seq_remove_events(snd_seq_t *handle, snd_seq_remove_events_t *info) { WARNX1("stub"); return 0; }
void snd_seq_set_bit(int nr, void *array) { WARNX1("stub");  }
void snd_seq_unset_bit(int nr, void *array) { WARNX1("stub");  }
int snd_seq_change_bit(int nr, void *array) { WARNX1("stub"); return 0; }
int snd_seq_get_bit(int nr, void *array) { WARNX1("stub"); return 0; }
int snd_midi_event_new(size_t bufsize, snd_midi_event_t **rdev) { WARNX1("stub"); return 0; }
int snd_midi_event_resize_buffer(snd_midi_event_t *dev, size_t bufsize) { WARNX1("stub"); return 0; }
void snd_midi_event_free(snd_midi_event_t *dev) { WARNX1("stub");  }
void snd_midi_event_init(snd_midi_event_t *dev) { WARNX1("stub");  }
void snd_midi_event_reset_encode(snd_midi_event_t *dev) { WARNX1("stub");  }
void snd_midi_event_reset_decode(snd_midi_event_t *dev) { WARNX1("stub");  }
void snd_midi_event_no_status(snd_midi_event_t *dev, int on) { WARNX1("stub");  }
long snd_midi_event_encode(snd_midi_event_t *dev, const unsigned char *buf, long count, snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
int snd_midi_event_encode_byte(snd_midi_event_t *dev, int c, snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
long snd_midi_event_decode(snd_midi_event_t *dev, unsigned char *buf, long count, const snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
int snd_seq_control_queue(snd_seq_t *seq, int q, int type, int value, snd_seq_event_t *ev) { WARNX1("stub"); return 0; }
int snd_seq_create_simple_port(snd_seq_t *seq, const char *name, unsigned int caps, unsigned int type) { WARNX1("stub"); return 0; }
int snd_seq_delete_simple_port(snd_seq_t *seq, int port) { WARNX1("stub"); return 0; }
int snd_seq_connect_from(snd_seq_t *seq, int my_port, int src_client, int src_port) { WARNX1("stub"); return 0; }
int snd_seq_connect_to(snd_seq_t *seq, int my_port, int dest_client, int dest_port) { WARNX1("stub"); return 0; }
int snd_seq_disconnect_from(snd_seq_t *seq, int my_port, int src_client, int src_port) { WARNX1("stub"); return 0; }
int snd_seq_disconnect_to(snd_seq_t *seq, int my_port, int dest_client, int dest_port) { WARNX1("stub"); return 0; }
int snd_seq_set_client_name(snd_seq_t *seq, const char *name) { WARNX1("stub"); return 0; }
int snd_seq_set_client_event_filter(snd_seq_t *seq, int event_type) { WARNX1("stub"); return 0; }
int snd_seq_set_client_pool_output(snd_seq_t *seq, size_t size) { WARNX1("stub"); return 0; }
int snd_seq_set_client_pool_output_room(snd_seq_t *seq, size_t size) { WARNX1("stub"); return 0; }
int snd_seq_set_client_pool_input(snd_seq_t *seq, size_t size) { WARNX1("stub"); return 0; }
int snd_seq_sync_output_queue(snd_seq_t *seq) { WARNX1("stub"); return 0; }
int snd_seq_parse_address(snd_seq_t *seq, snd_seq_addr_t *addr, const char *str) { WARNX1("stub"); return 0; }
int snd_seq_reset_pool_output(snd_seq_t *seq) { WARNX1("stub"); return 0; }
int snd_seq_reset_pool_input(snd_seq_t *seq) { WARNX1("stub"); return 0; }
int snd_timer_query_open(snd_timer_query_t **handle, const char *name, int mode) { WARNX1("stub"); return 0; }
int snd_timer_query_open_lconf(snd_timer_query_t **handle, const char *name, int mode, snd_config_t *lconf) { WARNX1("stub"); return 0; }
int snd_timer_query_close(snd_timer_query_t *handle) { WARNX1("stub"); return 0; }
int snd_timer_query_next_device(snd_timer_query_t *handle, snd_timer_id_t *tid) { WARNX1("stub"); return 0; }
int snd_timer_query_info(snd_timer_query_t *handle, snd_timer_ginfo_t *info) { WARNX1("stub"); return 0; }
int snd_timer_query_params(snd_timer_query_t *handle, snd_timer_gparams_t *params) { WARNX1("stub"); return 0; }
int snd_timer_query_status(snd_timer_query_t *handle, snd_timer_gstatus_t *status) { WARNX1("stub"); return 0; }
int snd_timer_open(snd_timer_t **handle, const char *name, int mode) { WARNX1("stub"); return 0; }
int snd_timer_open_lconf(snd_timer_t **handle, const char *name, int mode, snd_config_t *lconf) { WARNX1("stub"); return 0; }
int snd_timer_close(snd_timer_t *handle) { WARNX1("stub"); return 0; }
int snd_async_add_timer_handler(snd_async_handler_t **handler, snd_timer_t *timer, snd_async_callback_t callback, void *private_data) { WARNX1("stub"); return 0; }
snd_timer_t *snd_async_handler_get_timer(snd_async_handler_t *handler) { WARNX1("stub"); return NULL; }
int snd_timer_poll_descriptors_count(snd_timer_t *handle) { WARNX1("stub"); return 0; }
int snd_timer_poll_descriptors(snd_timer_t *handle, struct pollfd *pfds, unsigned int space) { WARNX1("stub"); return 0; }
int snd_timer_poll_descriptors_revents(snd_timer_t *timer, struct pollfd *pfds, unsigned int nfds, unsigned short *revents) { WARNX1("stub"); return 0; }
int snd_timer_info(snd_timer_t *handle, snd_timer_info_t *timer) { WARNX1("stub"); return 0; }
int snd_timer_params(snd_timer_t *handle, snd_timer_params_t *params) { WARNX1("stub"); return 0; }
int snd_timer_status(snd_timer_t *handle, snd_timer_status_t *status) { WARNX1("stub"); return 0; }
int snd_timer_start(snd_timer_t *handle) { WARNX1("stub"); return 0; }
int snd_timer_stop(snd_timer_t *handle) { WARNX1("stub"); return 0; }
int snd_timer_continue(snd_timer_t *handle) { WARNX1("stub"); return 0; }
ssize_t snd_timer_read(snd_timer_t *handle, void *buffer, size_t size) { WARNX1("stub"); return 0; }
size_t snd_timer_id_sizeof(void) { WARNX1("stub"); return 0; }
int snd_timer_id_malloc(snd_timer_id_t **ptr) { WARNX1("stub"); return 0; }
void snd_timer_id_free(snd_timer_id_t *obj) { WARNX1("stub");  }
void snd_timer_id_copy(snd_timer_id_t *dst, const snd_timer_id_t *src) { WARNX1("stub");  }
void snd_timer_id_set_class(snd_timer_id_t *id, int dev_class) { WARNX1("stub");  }
int snd_timer_id_get_class(snd_timer_id_t *id) { WARNX1("stub"); return 0; }
void snd_timer_id_set_sclass(snd_timer_id_t *id, int dev_sclass) { WARNX1("stub");  }
int snd_timer_id_get_sclass(snd_timer_id_t *id) { WARNX1("stub"); return 0; }
void snd_timer_id_set_card(snd_timer_id_t *id, int card) { WARNX1("stub");  }
int snd_timer_id_get_card(snd_timer_id_t *id) { WARNX1("stub"); return 0; }
void snd_timer_id_set_device(snd_timer_id_t *id, int device) { WARNX1("stub");  }
int snd_timer_id_get_device(snd_timer_id_t *id) { WARNX1("stub"); return 0; }
void snd_timer_id_set_subdevice(snd_timer_id_t *id, int subdevice) { WARNX1("stub");  }
int snd_timer_id_get_subdevice(snd_timer_id_t *id) { WARNX1("stub"); return 0; }
size_t snd_timer_ginfo_sizeof(void) { WARNX1("stub"); return 0; }
int snd_timer_ginfo_malloc(snd_timer_ginfo_t **ptr) { WARNX1("stub"); return 0; }
void snd_timer_ginfo_free(snd_timer_ginfo_t *obj) { WARNX1("stub");  }
void snd_timer_ginfo_copy(snd_timer_ginfo_t *dst, const snd_timer_ginfo_t *src) { WARNX1("stub");  }
int snd_timer_ginfo_set_tid(snd_timer_ginfo_t *obj, snd_timer_id_t *tid) { WARNX1("stub"); return 0; }
snd_timer_id_t *snd_timer_ginfo_get_tid(snd_timer_ginfo_t *obj) { WARNX1("stub"); return NULL; }
unsigned int snd_timer_ginfo_get_flags(snd_timer_ginfo_t *obj) { WARNX1("stub"); return 0; }
int snd_timer_ginfo_get_card(snd_timer_ginfo_t *obj) { WARNX1("stub"); return 0; }
char *snd_timer_ginfo_get_id(snd_timer_ginfo_t *obj) { WARNX1("stub"); return NULL; }
char *snd_timer_ginfo_get_name(snd_timer_ginfo_t *obj) { WARNX1("stub"); return NULL; }
unsigned long snd_timer_ginfo_get_resolution(snd_timer_ginfo_t *obj) { WARNX1("stub"); return 0; }
unsigned long snd_timer_ginfo_get_resolution_min(snd_timer_ginfo_t *obj) { WARNX1("stub"); return 0; }
unsigned long snd_timer_ginfo_get_resolution_max(snd_timer_ginfo_t *obj) { WARNX1("stub"); return 0; }
unsigned int snd_timer_ginfo_get_clients(snd_timer_ginfo_t *obj) { WARNX1("stub"); return 0; }
size_t snd_timer_info_sizeof(void) { WARNX1("stub"); return 0; }
int snd_timer_info_malloc(snd_timer_info_t **ptr) { WARNX1("stub"); return 0; }
void snd_timer_info_free(snd_timer_info_t *obj) { WARNX1("stub");  }
void snd_timer_info_copy(snd_timer_info_t *dst, const snd_timer_info_t *src) { WARNX1("stub");  }
int snd_timer_info_is_slave(snd_timer_info_t * info) { WARNX1("stub"); return 0; }
int snd_timer_info_get_card(snd_timer_info_t * info) { WARNX1("stub"); return 0; }
const char *snd_timer_info_get_id(snd_timer_info_t * info) { WARNX1("stub"); return NULL; }
const char *snd_timer_info_get_name(snd_timer_info_t * info) { WARNX1("stub"); return NULL; }
long snd_timer_info_get_resolution(snd_timer_info_t * info) { WARNX1("stub"); return 0; }
size_t snd_timer_params_sizeof(void) { WARNX1("stub"); return 0; }
int snd_timer_params_malloc(snd_timer_params_t **ptr) { WARNX1("stub"); return 0; }
void snd_timer_params_free(snd_timer_params_t *obj) { WARNX1("stub");  }
void snd_timer_params_copy(snd_timer_params_t *dst, const snd_timer_params_t *src) { WARNX1("stub");  }
int snd_timer_params_set_auto_start(snd_timer_params_t * params, int auto_start) { WARNX1("stub"); return 0; }
int snd_timer_params_get_auto_start(snd_timer_params_t * params) { WARNX1("stub"); return 0; }
int snd_timer_params_set_exclusive(snd_timer_params_t * params, int exclusive) { WARNX1("stub"); return 0; }
int snd_timer_params_get_exclusive(snd_timer_params_t * params) { WARNX1("stub"); return 0; }
int snd_timer_params_set_early_event(snd_timer_params_t * params, int early_event) { WARNX1("stub"); return 0; }
int snd_timer_params_get_early_event(snd_timer_params_t * params) { WARNX1("stub"); return 0; }
void snd_timer_params_set_ticks(snd_timer_params_t * params, long ticks) { WARNX1("stub");  }
long snd_timer_params_get_ticks(snd_timer_params_t * params) { WARNX1("stub"); return 0; }
void snd_timer_params_set_queue_size(snd_timer_params_t * params, long queue_size) { WARNX1("stub");  }
long snd_timer_params_get_queue_size(snd_timer_params_t * params) { WARNX1("stub"); return 0; }
void snd_timer_params_set_filter(snd_timer_params_t * params, unsigned int filter) { WARNX1("stub");  }
unsigned int snd_timer_params_get_filter(snd_timer_params_t * params) { WARNX1("stub"); return 0; }
size_t snd_timer_status_sizeof(void) { WARNX1("stub"); return 0; }
int snd_timer_status_malloc(snd_timer_status_t **ptr) { WARNX1("stub"); return 0; }
void snd_timer_status_free(snd_timer_status_t *obj) { WARNX1("stub");  }
void snd_timer_status_copy(snd_timer_status_t *dst, const snd_timer_status_t *src) { WARNX1("stub");  }
snd_htimestamp_t snd_timer_status_get_timestamp(snd_timer_status_t * status) { WARNX1("stub"); return (snd_htimestamp_t){0}; }
long snd_timer_status_get_resolution(snd_timer_status_t * status) { WARNX1("stub"); return 0; }
long snd_timer_status_get_lost(snd_timer_status_t * status) { WARNX1("stub"); return 0; }
long snd_timer_status_get_overrun(snd_timer_status_t * status) { WARNX1("stub"); return 0; }
long snd_timer_status_get_queue(snd_timer_status_t * status) { WARNX1("stub"); return 0; }
long snd_timer_info_get_ticks(snd_timer_info_t * info) { WARNX1("stub"); return 0; }
snd_tplg_t *snd_tplg_new(void) { WARNX1("stub"); return NULL; }
void snd_tplg_free(snd_tplg_t *tplg) { WARNX1("stub");  }
int snd_tplg_build_file(snd_tplg_t *tplg, const char *infile, const char *outfile) { WARNX1("stub"); return 0; }
void snd_tplg_verbose(snd_tplg_t *tplg, int verbose) { WARNX1("stub");  }
int snd_tplg_add_object(snd_tplg_t *tplg, snd_tplg_obj_template_t *t) { WARNX1("stub"); return 0; }
int snd_tplg_build(snd_tplg_t *tplg, const char *outfile) { WARNX1("stub"); return 0; }
int snd_tplg_set_manifest_data(snd_tplg_t *tplg, const void *data, int len) { WARNX1("stub"); return 0; }
int snd_tplg_set_version(snd_tplg_t *tplg, unsigned int version) { WARNX1("stub"); return 0; }
char *snd_use_case_identifier(const char *fmt, ...) { WARNX1("stub"); return NULL; }
int snd_use_case_free_list(const char *list[], int items) { WARNX1("stub"); return 0; }
int snd_use_case_get_list(snd_use_case_mgr_t *uc_mgr, const char *identifier, const char **list[]) { WARNX1("stub"); return 0; }
int snd_use_case_get(snd_use_case_mgr_t *uc_mgr, const char *identifier, const char **value) { WARNX1("stub"); return 0; }
int snd_use_case_geti(snd_use_case_mgr_t *uc_mgr, const char *identifier, long *value) { WARNX1("stub"); return 0; }
int snd_use_case_set(snd_use_case_mgr_t *uc_mgr, const char *identifier, const char *value) { WARNX1("stub"); return 0; }
int snd_use_case_mgr_open(snd_use_case_mgr_t **uc_mgr, const char *card_name) { WARNX1("stub"); return 0; }
int snd_use_case_mgr_reload(snd_use_case_mgr_t *uc_mgr) { WARNX1("stub"); return 0; }
int snd_use_case_mgr_close(snd_use_case_mgr_t *uc_mgr) { WARNX1("stub"); return 0; }
int snd_use_case_mgr_reset(snd_use_case_mgr_t *uc_mgr) { WARNX1("stub"); return 0; }
