// Created by Saveliy Borivets, group 3383

#include "../../headers/NaturalNumber.h"
#include <iostream>
#include "../../headers/Overload.h"

// N-8
NaturalNumber NaturalNumber::MUL_NN_N(const NaturalNumber& other) {
  NaturalNumber result = NaturalNumber("0");
  Node* cur_node = other.Big_int->get_first();
  NaturalNumber digit = NaturalNumber("0");
  while (cur_node != nullptr) {
    result = result.ADD_NN_N(((*this).MUL_ND_N(cur_node->value)).MUL_Nk_N(digit));
    digit = digit.ADD_1N_N();
    cur_node = cur_node->next;
  }
  return result;
}

// N-8 oper "*"
//NaturalNumber NaturalNumber::operator*(const NaturalNumber& other) {
//  return MUL_NN_N(other);
//}
//
//// N-8 oper "*="
//NaturalNumber NaturalNumber::operator*=(const NaturalNumber& other) {
//  (*this) = MUL_NN_N(other);
//  return *this;
//}

// N-9
NaturalNumber NaturalNumber::SUB_NDN_N(NaturalNumber& num, char c) { // Возвращает NN
  NaturalNumber result = *this;
  NaturalNumber sub_val = num.MUL_ND_N(c);
  if (result >= sub_val) {
    return result.SUB_NN_N(sub_val);
  }
  return *this;
}

// N-10
std::pair<char, NaturalNumber> NaturalNumber::DIV_NN_Dk(NaturalNumber& num) {
  if (*this < num) {
    return {0, NaturalNumber("0")};
  }
  NaturalNumber greater_num = (*this);
  NaturalNumber lower_num = num;
  Node *gr_node = greater_num.Big_int->get_first();
  Node *lw_node = lower_num.Big_int->get_first();
  NaturalNumber k = NaturalNumber("0");
  while (gr_node->next != nullptr) {
    if (lw_node == nullptr) {
      lower_num = lower_num.MUL_Nk_N(NaturalNumber("1"));
      k = k.ADD_1N_N();
    } else {
      lw_node = lw_node->next;
    }
    gr_node = gr_node->next;
  }
  if (greater_num >= lower_num.MUL_Nk_N(NaturalNumber("1"))) {
    lower_num = lower_num.MUL_Nk_N(NaturalNumber("1"));
    k = k.ADD_1N_N();
  }
  char cnt_subs = 0;
  while (greater_num >= lower_num) {
    greater_num = greater_num.SUB_NN_N(lower_num);
    greater_num.get_num().del_zero();
    cnt_subs++;
  }
  return {cnt_subs, k};
}

// N-11
NaturalNumber NaturalNumber::DIV_NN_N(NaturalNumber& num) {
  NaturalNumber divisible_num = *this;
  NaturalNumber result;
  std::pair<char, NaturalNumber> division_result;
  NaturalNumber sub_num;
  while (divisible_num >= num) {
    division_result = divisible_num.DIV_NN_Dk(num);
    result = result.ADD_NN_N(NaturalNumber(std::to_string(division_result.first)).MUL_Nk_N(division_result.second));
    sub_num = num.MUL_Nk_N(division_result.second);
    divisible_num = divisible_num.SUB_NDN_N(sub_num, division_result.first);
    divisible_num.get_num().del_zero();
  }
  return result;
}

// N-11 oper "/"
//NaturalNumber NaturalNumber::operator/(NaturalNumber& other) {
//  return DIV_NN_N(other);
//}
//
//// N-11 oper "/="
//NaturalNumber NaturalNumber::operator/=(NaturalNumber& other) {
//  (*this) = DIV_NN_N(other);
//  return *this;
//}

// N-12
NaturalNumber NaturalNumber::MOD_NN_N(NaturalNumber& num) {
  NaturalNumber result = (*this).SUB_NN_N(num.MUL_NN_N((*this).DIV_NN_N(num)));
  return result;
}

//// N-12 oper "%="
//NaturalNumber NaturalNumber::operator%(NaturalNumber& other) {
//  return MOD_NN_N(other);
//}
//
//// N-12 oper "%="
//NaturalNumber NaturalNumber::operator%=(NaturalNumber& other) {
//  (*this) = MOD_NN_N(other);
//  return *this;
//}

// N-13
NaturalNumber NaturalNumber::GCF_NN_N(NaturalNumber& arr_num) {
  NaturalNumber greater_num;
  NaturalNumber lower_num;
  if (*this > arr_num) {
    greater_num = *this;
    lower_num = arr_num;
  } else {
    greater_num = arr_num;
    lower_num = *this;
  }
  NaturalNumber tmp;
  while (lower_num.NZER_N_B()) {
    tmp = lower_num;
    lower_num = greater_num.MOD_NN_N(lower_num);
    greater_num = tmp;
  }
  return greater_num;
}

// N-14
NaturalNumber NaturalNumber::LCM_NN_N(NaturalNumber& arr_num) {
  NaturalNumber GCF = (*this).GCF_NN_N(arr_num);
  NaturalNumber LCM = (*this).MUL_NN_N(arr_num.DIV_NN_N(GCF));
  return LCM;
}