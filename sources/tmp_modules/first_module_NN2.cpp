// Created by Saveliy Borivets, group 3383

#include "../../headers/NaturalNumber.h"
#include <iostream>

// N-8
NaturalNumber& NaturalNumber::MUL_NN_N(const NaturalNumber& other) {
  NaturalNumber result = NaturalNumber("0");
  Node* cur_node = other.Big_int.get_first();
  size_t cnt_digit = 0;
  while (cur_node != nullptr) {
    result += (this * cur_node->value).MUL_Nk_N(NaturalNumber(std::to_string(cnt_digit)));
  }
  return result;
}

// N-9
NaturalNumber& NaturalNumber::SUB_NDN_N(NaturalNumber& num, char c) { // Возвращает NN
  NaturalNumber result = *this;
  NaturalNumber sub_val = num.MUL_ND_N(c);
  if (result >= sub_val) {
    return result - sub_val;
  }
  return *this;
}

// N-10
char NaturalNumber::DIV_NN_Dk(NaturalNumber& num) {
  NaturalNumber greater_num;
  NaturalNumber lower_num;
  if (*this > num) {
    greater_num = *this;
    lower_num = num;
  } else {
    greater_num = num;
    lower_num = *this;
  }
  Node *gr_node = greater_num.Big_int.get_first();
  Node *lw_node = lower_num.Big_int.get_first();
  while (gr_node->next != nullptr) {
    if (lw_node == nullptr) {
      lower_num.MUL_Nk_N(NaturalNumber("1"));
    } else {
      lw_node = lw_node->next;
    }
    gr_node = gr_node->next;
  }
  char cnt_subs = 0;
  while (greater_num.COM_NN_D(lower_num) != LESS) {
    greater_num.SUB_NN_N(lower_num);
    cnt_subs++;
  }
  return cnt_subs;
}

// N-11
NaturalNumber NaturalNumber::DIV_NN_N(NaturalNumber& num) {
  NaturalNumber result = *this;
  return result;
}

// N-12
NaturalNumber& NaturalNumber::MOD_NN_N(NaturalNumber& num) {
//  NaturalNumber result = (*this).SUB_NDN_N();
//  result = result.SUB_NDN_N()
}

// N-13
NaturalNumber& NaturalNumber::GCF_NN_N(NaturalNumber& arr_num) {
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
NaturalNumber& NaturalNumber::LCM_NN_N(NaturalNumber& arr_num) {
  NaturalNumber GCF = (*this).GCF_NN_N(arr_num);
  NaturalNumber LCM = (*this).DIV_NN_N(GCF) * (arr_num).DIV_NN_N(GCF);
}