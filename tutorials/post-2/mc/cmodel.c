#include "cmodel.h"
sol_raw_uint160_t global_index_const_0;
sol_uint256_t sol_pay(sol_uint256_t *bal, sol_uint256_t amt) {
  sol_require(((bal)->v) >= ((amt).v), 0);
  ((bal)->v) -= ((amt).v);
  return amt;
}
struct Crowdsale {
  sol_address_t model_address;
  sol_uint256_t model_balance;
  sol_uint256_t user_raised;
  sol_uint256_t user_goal;
  sol_uint256_t user_deadline;
  sol_bool_t user_finished;
  sol_bool_t user_canceled;
};
void Crowdsale_Constructor(struct Crowdsale *self, sol_address_t sender,
                           sol_uint256_t value, sol_uint256_t blocknum,
                           sol_uint256_t timestamp, sol_bool_t paid,
                           sol_address_t origin,
                           sol_uint256_t func_user___goal) {
  ((self->user_goal).v) = ((func_user___goal).v);
  ((self->user_deadline).v) = (((timestamp).v) + (31536000));
}
void Init_Crowdsale(struct Crowdsale *self, sol_address_t sender,
                    sol_uint256_t value, sol_uint256_t blocknum,
                    sol_uint256_t timestamp, sol_bool_t paid,
                    sol_address_t origin, sol_uint256_t user___goal) {
  ((self)->model_balance) = (Init_sol_uint256_t(0));
  ((self)->user_raised) = (Init_sol_uint256_t(0));
  ((self)->user_goal) = (Init_sol_uint256_t(0));
  ((self)->user_deadline) = (Init_sol_uint256_t(0));
  ((self)->user_finished) = (Init_sol_bool_t(0));
  ((self)->user_canceled) = (Init_sol_bool_t(0));
  Crowdsale_Constructor(self, sender, value, blocknum, timestamp,
                        Init_sol_bool_t(0), origin, user___goal);
}
void Crowdsale_Method_invest(struct Crowdsale *self, sol_address_t sender,
                             sol_uint256_t value, sol_uint256_t blocknum,
                             sol_uint256_t timestamp, sol_bool_t paid,
                             sol_address_t origin) {
  if (((paid).v) == (1))
    (((self)->model_balance).v) += ((value).v);
  sol_require(((timestamp).v) <= ((self->user_deadline).v), 0);
  ((self->user_raised).v) = (((self->user_raised).v) + ((value).v));
}
void Crowdsale_Method_finish(struct Crowdsale *self, sol_address_t sender,
                             sol_uint256_t value, sol_uint256_t blocknum,
                             sol_uint256_t timestamp, sol_bool_t paid,
                             sol_address_t origin) {
  sol_require((((self)->model_balance).v) >= ((self->user_goal).v), 0);
  ((self->user_finished).v) = (1);
}
void Crowdsale_Method_cancel(struct Crowdsale *self, sol_address_t sender,
                             sol_uint256_t value, sol_uint256_t blocknum,
                             sol_uint256_t timestamp, sol_bool_t paid,
                             sol_address_t origin) {
  sol_require(((((self)->model_balance).v) < ((self->user_goal).v)) &&
                  (((timestamp).v) > ((self->user_deadline).v)),
              0);
  ((self->user_canceled).v) = (1);
}
void Crowdsale_Method_repOK(struct Crowdsale *self, sol_address_t sender,
                            sol_uint256_t value, sol_uint256_t blocknum,
                            sol_uint256_t timestamp, sol_bool_t paid,
                            sol_address_t origin) {
  sol_assert(!(((self->user_finished).v) && ((self->user_canceled).v)), 0);
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
  struct Crowdsale contract_0;
  (global_index_const_0) = (0);
  (((contract_0).model_address).v) = (1);
  smartace_log("[Initializing contract_0]");
  ((sender).v) = (2);
  ((value).v) = (0);
  ((blocknum).v) = (nd_increase((blocknum).v, 0, "blocknum"));
  ((timestamp).v) = (nd_increase((timestamp).v, 0, "timestamp"));
  Init_Crowdsale(&(contract_0), sender, value, blocknum, timestamp, paid,
                 origin, Init_sol_uint256_t(nd_uint256_t("Crowdsale:_goal")));
  smartace_log("[Entering transaction loop]");
  while (sol_continue()) {
    sol_on_transaction();
    ((sender).v) = (2);
    ((value).v) = (0);
    ((blocknum).v) = (nd_increase((blocknum).v, 0, "blocknum"));
    ((timestamp).v) = (nd_increase((timestamp).v, 0, "timestamp"));
    uint8_t next_call;
    (next_call) = (nd_range(0, 4, "next_call"));
    switch (next_call) {
    case 0: {
      smartace_log("[Calling invest() on contract_0]");
      ((value).v) = (nd_uint256_t("value"));
      Crowdsale_Method_invest(&(contract_0), sender, value, blocknum, timestamp,
                              paid, origin);
      smartace_log("[Call successful]");
      break;
    }
    case 1: {
      smartace_log("[Calling finish() on contract_0]");
      Crowdsale_Method_finish(&(contract_0), sender, value, blocknum, timestamp,
                              paid, origin);
      smartace_log("[Call successful]");
      break;
    }
    case 2: {
      smartace_log("[Calling cancel() on contract_0]");
      Crowdsale_Method_cancel(&(contract_0), sender, value, blocknum, timestamp,
                              paid, origin);
      smartace_log("[Call successful]");
      break;
    }
    case 3: {
      smartace_log("[Calling repOK() on contract_0]");
      Crowdsale_Method_repOK(&(contract_0), sender, value, blocknum, timestamp,
                             paid, origin);
      smartace_log("[Call successful]");
      break;
    }
    default: { sol_require(0, 0); }
    }
  }
}
