#pragma once
#include "libverify/verify.h"
struct sol_bool {
  sol_raw_uint8_t v;
};
typedef struct sol_bool sol_bool_t;
static inline sol_bool_t Init_sol_bool_t(sol_raw_uint8_t v) {
  sol_bool_t tmp;
  ((tmp).v) = (v);
  return tmp;
}
struct sol_address {
  sol_raw_uint160_t v;
};
typedef struct sol_address sol_address_t;
static inline sol_address_t Init_sol_address_t(sol_raw_uint160_t v) {
  sol_address_t tmp;
  ((tmp).v) = (v);
  return tmp;
}
struct sol_uint8 {
  sol_raw_uint8_t v;
};
typedef struct sol_uint8 sol_uint8_t;
static inline sol_uint8_t Init_sol_uint8_t(sol_raw_uint8_t v) {
  sol_uint8_t tmp;
  ((tmp).v) = (v);
  return tmp;
}
struct sol_uint64 {
  sol_raw_uint64_t v;
};
typedef struct sol_uint64 sol_uint64_t;
static inline sol_uint64_t Init_sol_uint64_t(sol_raw_uint64_t v) {
  sol_uint64_t tmp;
  ((tmp).v) = (v);
  return tmp;
}
struct sol_uint256 {
  sol_raw_uint256_t v;
};
typedef struct sol_uint256 sol_uint256_t;
static inline sol_uint256_t Init_sol_uint256_t(sol_raw_uint256_t v) {
  sol_uint256_t tmp;
  ((tmp).v) = (v);
  return tmp;
}