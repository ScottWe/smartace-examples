#pragma once
#include "primitive.h"
void run_model(void);
sol_uint256_t sol_pay(sol_uint256_t *bal, sol_uint256_t amt);
struct Fund;
struct Manager;
void Fund_Constructor(struct Fund *self, sol_address_t sender,
                      sol_uint256_t value, sol_uint256_t blocknum,
                      sol_uint256_t timestamp, sol_bool_t paid,
                      sol_address_t origin);
void Init_Fund(struct Fund *self, sol_address_t sender, sol_uint256_t value,
               sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
               sol_address_t origin);
void Fund_Method_claim(struct Fund *self, sol_address_t sender,
                       sol_uint256_t value, sol_uint256_t blocknum,
                       sol_uint256_t timestamp, sol_bool_t paid,
                       sol_address_t origin);
void Fund_Method_open(struct Fund *self, sol_address_t sender,
                      sol_uint256_t value, sol_uint256_t blocknum,
                      sol_uint256_t timestamp, sol_bool_t paid,
                      sol_address_t origin);
void Fund_Method_close(struct Fund *self, sol_address_t sender,
                       sol_uint256_t value, sol_uint256_t blocknum,
                       sol_uint256_t timestamp, sol_bool_t paid,
                       sol_address_t origin);
void Fund_Method_deposit(struct Fund *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin);
void Manager_Constructor(struct Manager *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin);
void Init_Manager(struct Manager *self, sol_address_t sender,
                  sol_uint256_t value, sol_uint256_t blocknum,
                  sol_uint256_t timestamp, sol_bool_t paid,
                  sol_address_t origin);
void Manager_Method_openFund(struct Manager *self, sol_address_t sender,
                             sol_uint256_t value, sol_uint256_t blocknum,
                             sol_uint256_t timestamp, sol_bool_t paid,
                             sol_address_t origin);