/* Copyright (C) 2009-2014 Kentoku Shiba

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

uchar *vp_tbl_get_key(
  VP_SHARE *share,
  size_t *length,
  my_bool not_used __attribute__ ((unused))
);

#ifdef WITH_PARTITION_STORAGE_ENGINE
uchar *vp_pt_share_get_key(
  VP_PARTITION_SHARE *share,
  size_t *length,
  my_bool not_used __attribute__ ((unused))
);

uchar *vp_pt_handler_share_get_key(
  VP_PARTITION_HANDLER_SHARE *share,
  size_t *length,
  my_bool not_used __attribute__ ((unused))
);
#endif

int vp_free_share_alloc(
  VP_SHARE *share
);

char *vp_get_string_between_quote(
  char *ptr,
  bool alloc
);

int vp_parse_table_info(
  VP_SHARE *share,
  TABLE *table,
  uint create_table
);

int vp_set_table_info_default(
  VP_SHARE *share,
#ifdef WITH_PARTITION_STORAGE_ENGINE
  partition_element *part_elem,
  partition_element *sub_elem,
#endif
  TABLE *table
);

VP_SHARE *vp_get_share(
  const char *table_name,
  TABLE *table,
  const THD *thd,
  ha_vp *vp,
  int *error_num
);

int vp_free_share(
  VP_SHARE *vp
);

#ifdef WITH_PARTITION_STORAGE_ENGINE
VP_PARTITION_SHARE *vp_get_pt_share(
  TABLE *table,
  VP_SHARE *share,
  int *error_num
);

int vp_free_pt_share(
  VP_PARTITION_SHARE *partition_share
);
#endif

bool vp_flush_logs(
  handlerton *hton
);

handler* vp_create_handler(
  handlerton *hton,
  TABLE_SHARE *table, 
  MEM_ROOT *mem_root
);

int vp_close_connection(
  handlerton* hton,
  THD* thd
);

void vp_drop_database(
  handlerton *hton,
  char* path
);

bool vp_show_status(
  handlerton *hton,
  THD *thd,
  stat_print_fn *stat_print,
  enum ha_stat_type stat_type
);

int vp_start_consistent_snapshot(
  handlerton *hton,
  THD* thd
);

int vp_commit(
  handlerton *hton,
  THD *thd,
  bool all
);

int vp_rollback(
  handlerton *hton,
  THD *thd,
  bool all
);

int vp_xa_prepare(
  handlerton *hton,
  THD* thd,
  bool all
);

int vp_xa_recover(
  handlerton *hton,
  XID* xid_list,
  uint len
);

int vp_xa_commit_by_xid(
  handlerton *hton,
  XID* xid
);

int vp_xa_rollback_by_xid(
  handlerton *hton,
  XID* xid
);

int vp_db_done(
  void *p
);

int vp_panic(
  handlerton *hton,
  ha_panic_function type
);

int vp_db_init(
  void *p
);

char *vp_create_string(
  const char *str,
  uint length
);

char *vp_create_table_name_string(
  const char *table_name,
  const char *part_name,
  const char *sub_name
);

#ifdef WITH_PARTITION_STORAGE_ENGINE
void vp_get_partition_info(
  const char *table_name,
  const TABLE *table,
  partition_element **part_elem,
  partition_element **sub_elem
);
#endif

int vp_create_table_list(
  VP_SHARE *share
);

int vp_correspond_columns(
  ha_vp *vp,
  TABLE *table,
  VP_SHARE *share,
  TABLE_SHARE *table_share,
  TABLE_LIST *part_tables,
  bool reinit
);

uchar vp_bit_count(
  uchar bitmap
);

void *vp_bg_action(
  void *arg
);

int vp_table_num_list_to_bitmap(
  VP_SHARE *share,
  char *table_num_list,
  uchar *bitmap
);
