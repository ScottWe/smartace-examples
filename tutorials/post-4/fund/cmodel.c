#include "cmodel.h"
sol_raw_uint160_t global_index_const_0;
sol_uint256_t sol_pay(sol_uint256_t *bal, sol_uint256_t amt) {
  sol_require(((bal)->v) >= ((amt).v), 0);
  ((bal)->v) -= ((amt).v);
  return amt;
}
struct Fund {
  sol_address_t model_address;
  sol_uint256_t model_balance;
  sol_bool_t user_isOpen;
  sol_address_t user_owner;
};
struct Manager {
  sol_address_t model_address;
  sol_uint256_t model_balance;
  struct Fund user_fund;
};
void Fund_Constructor(struct Fund *self, sol_address_t sender,
                      sol_uint256_t value, sol_uint256_t blocknum,
                      sol_uint256_t timestamp, sol_bool_t paid,
                      sol_address_t origin) {
  ((self->user_owner).v) = ((sender).v);
}
void Init_Fund(struct Fund *self, sol_address_t sender, sol_uint256_t value,
               sol_uint256_t blocknum, sol_uint256_t timestamp, sol_bool_t paid,
               sol_address_t origin) {
  ((self)->model_balance) = (Init_sol_uint256_t(0));
  ((self)->user_isOpen) = (Init_sol_bool_t(0));
  ((self)->user_owner) = (Init_sol_address_t(0));
  Fund_Constructor(self, sender, value, blocknum, timestamp, Init_sol_bool_t(0),
                   origin);
}
void Fund_Method_1_releaseTo(struct Fund *self, sol_address_t sender,
                             sol_uint256_t value, sol_uint256_t blocknum,
                             sol_uint256_t timestamp, sol_bool_t paid,
                             sol_address_t origin,
                             sol_address_t func_user___new) {
  ((self->user_owner).v) = ((func_user___new).v);
}
void Fund_Method_releaseTo(struct Fund *self, sol_address_t sender,
                           sol_uint256_t value, sol_uint256_t blocknum,
                           sol_uint256_t timestamp, sol_bool_t paid,
                           sol_address_t origin,
                           sol_address_t func_model___new) {
  sol_require(((self->user_owner).v) == ((sender).v), 0);
  Fund_Method_1_releaseTo(self, sender, value, blocknum, timestamp,
                          Init_sol_bool_t(0), origin, func_model___new);
}
void Fund_Method_1_open(struct Fund *self, sol_address_t sender,
                        sol_uint256_t value, sol_uint256_t blocknum,
                        sol_uint256_t timestamp, sol_bool_t paid,
                        sol_address_t origin) {
  ((self->user_isOpen).v) = (1);
}
void Fund_Method_open(struct Fund *self, sol_address_t sender,
                      sol_uint256_t value, sol_uint256_t blocknum,
                      sol_uint256_t timestamp, sol_bool_t paid,
                      sol_address_t origin) {
  sol_require(((self->user_owner).v) == ((sender).v), 0);
  Fund_Method_1_open(self, sender, value, blocknum, timestamp,
                     Init_sol_bool_t(0), origin);
}
void Fund_Method_1_close(struct Fund *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin) {
  ((self->user_isOpen).v) = (0);
}
void Fund_Method_close(struct Fund *self, sol_address_t sender,
                       sol_uint256_t value, sol_uint256_t blocknum,
                       sol_uint256_t timestamp, sol_bool_t paid,
                       sol_address_t origin) {
  sol_require(((self->user_owner).v) == ((sender).v), 0);
  Fund_Method_1_close(self, sender, value, blocknum, timestamp,
                      Init_sol_bool_t(0), origin);
}
void Fund_Method_deposit(struct Fund *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin) {
  if (((paid).v) == (1))
    (((self)->model_balance).v) += ((value).v);
  sol_require((self->user_isOpen).v, 0);
}
void Manager_Constructor(struct Manager *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin) {
  Init_Fund(&(self->user_fund), (self)->model_address, Init_sol_uint256_t(0),
            blocknum, timestamp, Init_sol_bool_t(1), origin);
}
void Init_Manager(struct Manager *self, sol_address_t sender,
                  sol_uint256_t value, sol_uint256_t blocknum,
                  sol_uint256_t timestamp, sol_bool_t paid,
                  sol_address_t origin) {
  ((self)->model_balance) = (Init_sol_uint256_t(0));
  Manager_Constructor(self, sender, value, blocknum, timestamp,
                      Init_sol_bool_t(0), origin);
}
void Manager_Method_openFund(struct Manager *self, sol_address_t sender,
                             sol_uint256_t value, sol_uint256_t blocknum,
                             sol_uint256_t timestamp, sol_bool_t paid,
                             sol_address_t origin) {
  Fund_Method_open(&(self->user_fund), (self)->model_address,
                   Init_sol_uint256_t(0), blocknum, timestamp,
                   Init_sol_bool_t(1), origin);
}
void run_model(void) {
  sol_address_t sender;
  sol_uint256_t value;
  sol_uint256_t blocknum;
  ((blocknum).v) = (0);
  sol_uint256_t timestamp;
  ((timestamp).v) = (0);
  sol_bool_t paid;
  ((paid).v) = (1);
  sol_address_t origin;
  struct Manager contract_0;
  struct Fund *contract_1;
  (global_index_const_0) = (0);
  (((contract_0).model_address).v) = (1);
  (contract_1) = (&((contract_0).user_fund));
  (((contract_1)->model_address).v) = (2);
  (((contract_1)->user_owner).v) = (0);
  smartace_log("[Initializing contract_0 and children.]");
  ((sender).v) = (nd_range(3, 6, "sender"));
  ((value).v) = (0);
  ((blocknum).v) = (nd_increase((blocknum).v, 0, "blocknum"));
  ((timestamp).v) = (nd_increase((timestamp).v, 0, "timestamp"));
  Init_Manager(&(contract_0), sender, value, blocknum, timestamp, paid, origin);
  smartace_log("[Entering transaction loop]");
  while (sol_continue()) {
    sol_on_transaction();
    ((sender).v) = (nd_range(3, 6, "sender"));
    ((value).v) = (0);
    ((blocknum).v) = (nd_increase((blocknum).v, 0, "blocknum"));
    ((timestamp).v) = (nd_increase((timestamp).v, 0, "timestamp"));
    uint8_t next_call;
    (next_call) = (nd_range(0, 5, "next_call"));
    switch (next_call) {
    case 0: {
      smartace_log("Calling openFund() on contract_0]");
      Manager_Method_openFund(&(contract_0), sender, value, blocknum, timestamp,
                              paid, origin);
      smartace_log("[Call successful]");
      break;
    }
    case 1: {
      smartace_log("Calling releaseTo(_new) on contract_1]");
      sol_address_t arg__new = Init_sol_address_t(nd_range(0, 6, "_new"));
      Fund_Method_releaseTo(contract_1, sender, value, blocknum, timestamp,
                            paid, origin, arg__new);
      smartace_log("[Call successful]");
      break;
    }
    case 2: {
      smartace_log("Calling open() on contract_1]");
      Fund_Method_open(contract_1, sender, value, blocknum, timestamp, paid,
                       origin);
      smartace_log("[Call successful]");
      break;
    }
    case 3: {
      smartace_log("Calling close() on contract_1]");
      Fund_Method_close(contract_1, sender, value, blocknum, timestamp, paid,
                        origin);
      smartace_log("[Call successful]");
      break;
    }
    case 4: {
      smartace_log("Calling deposit() on contract_1]");
      ((value).v) = (nd_uint256_t("value"));
      Fund_Method_deposit(contract_1, sender, value, blocknum, timestamp, paid,
                          origin);
      smartace_log("[Call successful]");
      break;
    }
    default: { sol_require(0, 0); }
    }
  }
}