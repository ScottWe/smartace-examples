#include "cmodel.h"
sol_raw_uint160_t g_literal_address_0;
sol_uint256_t sol_pay(sol_uint256_t *bal, sol_uint256_t amt) {
  sol_require(((bal)->v) >= ((amt).v), "Insufficient funds to call.");
  ((bal)->v) -= ((amt).v);
  return amt;
}
uint8_t sol_send(sol_uint256_t *bal, sol_address_t dst, sol_uint256_t amt) {
  if (((bal)->v) < ((amt).v))
    return 0;
  if (((dst).v) == (0)) {
    return 0;
  }
  if (((dst).v) == (1)) {
    return 0;
  }
  ((bal)->v) -= ((amt).v);
  return nd_byte("Return value for send/transfer.");
}
void sol_transfer(sol_uint256_t *bal, sol_address_t dst, sol_uint256_t amt) {
  sol_require(sol_send(bal, dst, amt), "Transfer failed.");
}
struct Map_1 {
  sol_uint256_t data_0;
  sol_uint256_t data_1;
  sol_uint256_t data_2;
  sol_uint256_t data_3;
  sol_uint256_t data_4;
  sol_uint256_t data_5;
};
struct Auction {
  sol_address_t model_address;
  sol_uint256_t model_balance;
  sol_bool_t user_isOpen;
  sol_address_t user_owner;
  sol_uint256_t user_maxBid;
  struct Map_1 user_bids;
};
struct Manager {
  sol_address_t model_address;
  sol_uint256_t model_balance;
  struct Auction user_auction;
};
struct Map_1 ZeroInit_Map_1(void);
sol_uint256_t Read_Map_1(struct Map_1 *arr, sol_address_t key_0);
void Write_Map_1(struct Map_1 *arr, sol_address_t key_0, sol_uint256_t dat);
void Set_Map_1(struct Map_1 *arr, sol_address_t key_0, sol_uint256_t dat);
void Manager_Constructor(struct Manager *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin) {
  Init_Auction(&(self->user_auction), (self)->model_address,
               Init_sol_uint256_t(0), blocknum, timestamp, Init_sol_bool_t(1),
               origin);
}
void Init_Manager(struct Manager *self, sol_address_t sender,
                  sol_uint256_t value, sol_uint256_t blocknum,
                  sol_uint256_t timestamp, sol_bool_t paid,
                  sol_address_t origin) {
  ((self)->model_balance) = (Init_sol_uint256_t(0));
  Manager_Constructor(self, sender, value, blocknum, timestamp,
                      Init_sol_bool_t(0), origin);
}
void Manager_Method_openAuction(struct Manager *self, sol_address_t sender,
                                sol_uint256_t value, sol_uint256_t blocknum,
                                sol_uint256_t timestamp, sol_bool_t paid,
                                sol_address_t origin) {
  Auction_Method_open(&(self->user_auction), (self)->model_address,
                      Init_sol_uint256_t(0), blocknum, timestamp,
                      Init_sol_bool_t(1), origin);
}
struct Map_1 ZeroInit_Map_1(void) {
  struct Map_1 tmp;
  ((tmp).data_0) = (Init_sol_uint256_t(0));
  ((tmp).data_1) = (Init_sol_uint256_t(0));
  ((tmp).data_2) = (Init_sol_uint256_t(0));
  ((tmp).data_3) = (Init_sol_uint256_t(0));
  ((tmp).data_4) = (Init_sol_uint256_t(0));
  ((tmp).data_5) = (Init_sol_uint256_t(0));
  return tmp;
}
sol_uint256_t Read_Map_1(struct Map_1 *arr, sol_address_t key_0) {
  {
    sol_assert((6) >= ((key_0).v), "Model failure, mapping key out of bounds.");
    if ((5) == ((key_0).v))
      return (arr)->data_5;
    else if ((4) == ((key_0).v))
      return (arr)->data_4;
    else if ((3) == ((key_0).v))
      return (arr)->data_3;
    else if ((2) == ((key_0).v))
      return (arr)->data_2;
    else if ((1) == ((key_0).v))
      return (arr)->data_1;
    else if ((0) == ((key_0).v))
      return (arr)->data_0;
  }
  return Init_sol_uint256_t(0);
}
void Write_Map_1(struct Map_1 *arr, sol_address_t key_0, sol_uint256_t dat) {
  {
    sol_assert((6) >= ((key_0).v), "Model failure, mapping key out of bounds.");
    if ((5) == ((key_0).v)) {
      ((arr)->data_5) = (dat);
    } else if ((4) == ((key_0).v)) {
      ((arr)->data_4) = (dat);
    } else if ((3) == ((key_0).v)) {
      ((arr)->data_3) = (dat);
    } else if ((2) == ((key_0).v)) {
      ((arr)->data_2) = (dat);
    } else if ((1) == ((key_0).v)) {
      ((arr)->data_1) = (dat);
    } else if ((0) == ((key_0).v)) {
      ((arr)->data_0) = (dat);
    }
  }
}
void Set_Map_1(struct Map_1 *arr, sol_address_t key_0, sol_uint256_t dat) {
  Write_Map_1(arr, key_0, dat);
}
void Auction_Constructor(struct Auction *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin) {
  ((self->user_owner).v) = ((sender).v);
}
void Init_Auction(struct Auction *self, sol_address_t sender,
                  sol_uint256_t value, sol_uint256_t blocknum,
                  sol_uint256_t timestamp, sol_bool_t paid,
                  sol_address_t origin) {
  ((self)->model_balance) = (Init_sol_uint256_t(0));
  ((self)->user_isOpen) = (Init_sol_bool_t(0));
  ((self)->user_owner) = (Init_sol_address_t(0));
  ((self)->user_maxBid) = (Init_sol_uint256_t(0));
  ((self)->user_bids) = (ZeroInit_Map_1());
  Auction_Constructor(self, sender, value, blocknum, timestamp,
                      Init_sol_bool_t(0), origin);
}
void Auction_Method_1_releaseTo(struct Auction *self, sol_address_t sender,
                                sol_uint256_t value, sol_uint256_t blocknum,
                                sol_uint256_t timestamp, sol_bool_t paid,
                                sol_address_t origin,
                                sol_address_t func_user___new) {
  ((self->user_owner).v) = ((func_user___new).v);
}
void Auction_Method_releaseTo(struct Auction *self, sol_address_t sender,
                              sol_uint256_t value, sol_uint256_t blocknum,
                              sol_uint256_t timestamp, sol_bool_t paid,
                              sol_address_t origin,
                              sol_address_t func_model___new) {
  sol_require(((self->user_owner).v) == ((sender).v), 0);
  Auction_Method_1_releaseTo(self, sender, value, blocknum, timestamp,
                             Init_sol_bool_t(0), origin, func_model___new);
}
void Auction_Method_1_open(struct Auction *self, sol_address_t sender,
                           sol_uint256_t value, sol_uint256_t blocknum,
                           sol_uint256_t timestamp, sol_bool_t paid,
                           sol_address_t origin) {
  ((self->user_isOpen).v) = (1);
}
void Auction_Method_open(struct Auction *self, sol_address_t sender,
                         sol_uint256_t value, sol_uint256_t blocknum,
                         sol_uint256_t timestamp, sol_bool_t paid,
                         sol_address_t origin) {
  sol_require(((self->user_owner).v) == ((sender).v), 0);
  Auction_Method_1_open(self, sender, value, blocknum, timestamp,
                        Init_sol_bool_t(0), origin);
}
void Auction_Method_1_close(struct Auction *self, sol_address_t sender,
                            sol_uint256_t value, sol_uint256_t blocknum,
                            sol_uint256_t timestamp, sol_bool_t paid,
                            sol_address_t origin) {
  ((self->user_isOpen).v) = (0);
}
void Auction_Method_close(struct Auction *self, sol_address_t sender,
                          sol_uint256_t value, sol_uint256_t blocknum,
                          sol_uint256_t timestamp, sol_bool_t paid,
                          sol_address_t origin) {
  sol_require(((self->user_owner).v) == ((sender).v), 0);
  Auction_Method_1_close(self, sender, value, blocknum, timestamp,
                         Init_sol_bool_t(0), origin);
}
void Auction_Method_deposit(struct Auction *self, sol_address_t sender,
                            sol_uint256_t value, sol_uint256_t blocknum,
                            sol_uint256_t timestamp, sol_bool_t paid,
                            sol_address_t origin) {
  if (((paid).v) == (1))
    (((self)->model_balance).v) += ((value).v);
  sol_uint256_t func_user_bid = Init_sol_uint256_t(
      ((Read_Map_1(&(self->user_bids), Init_sol_address_t((sender).v))).v) +
      ((value).v));
  sol_require((self->user_isOpen).v, 0);
  sol_require(((func_user_bid).v) > ((self->user_maxBid).v), 0);
  Write_Map_1(&(self->user_bids), Init_sol_address_t((sender).v),
              Init_sol_uint256_t((func_user_bid).v));
  ((self->user_maxBid).v) = ((func_user_bid).v);
}
void Auction_Method_withdraw(struct Auction *self, sol_address_t sender,
                             sol_uint256_t value, sol_uint256_t blocknum,
                             sol_uint256_t timestamp, sol_bool_t paid,
                             sol_address_t origin) {
  if (((paid).v) == (1))
    (((self)->model_balance).v) += ((value).v);
  sol_uint256_t func_user_bid = Init_sol_uint256_t(
      (Read_Map_1(&(self->user_bids), Init_sol_address_t((sender).v))).v);
  sol_require((self->user_isOpen).v, 0);
  sol_require(((func_user_bid).v) < ((self->user_maxBid).v), 0);
  Write_Map_1(&(self->user_bids), Init_sol_address_t((sender).v),
              Init_sol_uint256_t(0));
  sol_transfer(&((self)->model_balance), Init_sol_address_t((sender).v),
               Init_sol_uint256_t((func_user_bid).v));
}
// [START] INSTRUMENTED
int property(struct Manager *c0, sol_address_t addr)
{
  sol_uint256_t bid = Read_Map_1(&(c0->user_auction.user_bids), addr);
  sol_uint256_t maximum = c0->user_auction.user_maxBid;
  return bid.v <= maximum.v;
}
int invariant(struct Manager *c0)
{
  sol_uint256_t maximum = c0->user_auction.user_maxBid;
  for (int i = 0; i < 6; ++i)
  {
    sol_address_t addr = Init_sol_address_t(i);
    sol_uint256_t bid = Read_Map_1(&(c0->user_auction.user_bids), addr);
    if (bid.v > maximum.v) return 0;
  }
  return 1;
}
// [ END ] INSTRUMENTED
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
  struct Auction *contract_1;
  (g_literal_address_0) = (0);
  (((contract_0).model_address).v) = (1);
  (contract_1) = (&((contract_0).user_auction));
  (((contract_1)->model_address).v) = (2);
  (((contract_1)->user_owner).v) = (0);
  smartace_log("[Initializing contract_0 and children]");
  ((sender).v) = (nd_range(3, 6, "sender"));
  ((value).v) = (0);
  ((blocknum).v) = (nd_increase((blocknum).v, 0, "blocknum"));
  ((timestamp).v) = (nd_increase((timestamp).v, 0, "timestamp"));
  Init_Manager(&(contract_0), sender, value, blocknum, timestamp, paid, origin);
  smartace_log("[Entering transaction loop]");
  // [START] INSTRUMENTATION
  sol_uint256_t ZERO = Init_sol_uint256_t(0);
  if (nd_range(0, 2, "Use external address(3)")) {
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(3), ZERO);
  }
  if (nd_range(0, 2, "Use external address(4)")) {
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(4), ZERO);
  }
  if (nd_range(0, 2, "Use external address(5)")) {
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(5), ZERO);
  }
  sol_assert(invariant(&contract_0), "Initialization is violated.");
  // [ END ] INSTRUMENTATION
  while (sol_continue()) {
    // [START] INSTRUMENTATION
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(3),
                Init_sol_uint256_t(nd_uint256_t("external bids[3]")));
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(4),
                Init_sol_uint256_t(nd_uint256_t("external bids[4]")));
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(5),
                Init_sol_uint256_t(nd_uint256_t("external bids[5]")));
    sol_uint256_t extern_3
      = Read_Map_1(&contract_1->user_bids, Init_sol_address_t(3));
    sol_uint256_t extern_4
      = Read_Map_1(&contract_1->user_bids, Init_sol_address_t(4));
    sol_uint256_t extern_5
      = Read_Map_1(&contract_1->user_bids, Init_sol_address_t(5));
    sol_require(invariant(&contract_0), "Bad arrangement.");
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(3),
                Init_sol_uint256_t(nd_uint256_t("bids[3]")));
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(4),
                Init_sol_uint256_t(nd_uint256_t("bids[4]")));
    Write_Map_1(&contract_1->user_bids, Init_sol_address_t(5),
                Init_sol_uint256_t(nd_uint256_t("bids[5]")));
    sol_require(invariant(&contract_0), "Bad arrangement.");
    // [ END ] INSTRUMENTATION
    sol_on_transaction();
    ((sender).v) = (nd_range(3, 6, "sender"));
    ((value).v) = (0);
    ((blocknum).v) = (nd_increase((blocknum).v, 0, "blocknum"));
    ((timestamp).v) = (nd_increase((timestamp).v, 0, "timestamp"));
    uint8_t next_call;
    (next_call) = (nd_range(0, 6, "next_call"));
    switch (next_call) {
    case 0: {
      smartace_log("[Calling openAuction() on contract_0]");
      Manager_Method_openAuction(&(contract_0), sender, value, blocknum,
                                 timestamp, paid, origin);
      smartace_log("[Call successful]");
      break;
    }
    case 1: {
      smartace_log("[Calling releaseTo(_new) on contract_1]");
      sol_address_t arg__new = Init_sol_address_t(nd_range(0, 6, "_new"));
      Auction_Method_releaseTo(contract_1, sender, value, blocknum, timestamp,
                               paid, origin, arg__new);
      smartace_log("[Call successful]");
      break;
    }
    case 2: {
      smartace_log("[Calling open() on contract_1]");
      Auction_Method_open(contract_1, sender, value, blocknum, timestamp, paid,
                          origin);
      smartace_log("[Call successful]");
      break;
    }
    case 3: {
      smartace_log("[Calling close() on contract_1]");
      Auction_Method_close(contract_1, sender, value, blocknum, timestamp, paid,
                           origin);
      smartace_log("[Call successful]");
      break;
    }
    case 4: {
      smartace_log("[Calling deposit() on contract_1]");
      ((value).v) = (nd_uint256_t("value"));
      Auction_Method_deposit(contract_1, sender, value, blocknum, timestamp,
                             paid, origin);
      smartace_log("[Call successful]");
      break;
    }
    case 5: {
      smartace_log("[Calling withdraw() on contract_1]");
      ((value).v) = (nd_uint256_t("value"));
      Auction_Method_withdraw(contract_1, sender, value, blocknum, timestamp,
                              paid, origin);
      smartace_log("[Call successful]");
      break;
    }
    default: { sol_require(0, "Model failure, next_call out of bounds."); }
    }
    // [START] INSTRUMENTATION
    sol_assert(invariant(&contract_0), "Local Inductiveness is violated.");
    if (nd_range(0, 2, "Use external address(3)")) {
      Write_Map_1(&contract_1->user_bids, Init_sol_address_t(3), extern_3);
    }
    if (nd_range(0, 2, "Use external address(4)")) {
      Write_Map_1(&contract_1->user_bids, Init_sol_address_t(4), extern_4);
    }
    if (nd_range(0, 2, "Use external address(5)")) {
      Write_Map_1(&contract_1->user_bids, Init_sol_address_t(5), extern_5);
    }
    sol_assert(invariant(&contract_0), "Non-interference is violated.");
    // [ END ] INSTRUMENTATION
  }
}
