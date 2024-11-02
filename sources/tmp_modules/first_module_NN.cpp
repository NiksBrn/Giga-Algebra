#include "../../headers/NaturalNumber.h"
#include <iostream>

Compare NaturalNumber::COM_NN_D(const NaturalNumber& other) const
{
    Node* next_node1 = Big_int.get_last();//������ ����� ������� �����
    Node* next_node2 = other.Big_int.get_last();//������ ����� ������� �����

    while ((next_node1->next!=nullptr) && (next_node2->next!=nullptr)) { //���� ��� ��������� ���� �������� ����� �����

        int num1 = next_node1->value; //�������� i-�� ������� ������� �����
        int num2 = next_node2->value; //�������� i-�� ������� ������� �����

        if (num1 > num2) { //��������� ���� ��������
            return GREATER;
        }
        if (num1 < num2) {
            return LESS;
        }

        next_node1 = next_node1->next;//����� �� ��������� ������ ������� �����
        next_node2 = next_node2->next; //����� �� ��������� ������ ������� �����

    }
    if ((next_node1->next != nullptr) && (next_node2->next == nullptr)) { // ���� ������ ������� ����� ������ ������� �������
        return GREATER;
    }
    if ((next_node1->next == nullptr) && (next_node2->next != nullptr)) { // ���� ������ ������� ����� ������ ������� �������
        return LESS;
    }
    return EQUAL; //���� ����� �����
}

bool NaturalNumber::NZER_N_B()
{
    if ((Big_int.get_first()->next == nullptr) && (Big_int.get_first()->value == 0)) {// �������� ����� �� 0
        return false; // ���� ����� ����� 0, �� false
    }

    return true;
}

void NaturalNumber::ADD_1N_N()
{
    Node* next_node = Big_int.get_first();//�������� �� ����� �� ��������� ������ �����

    while (next_node->next != nullptr) { // ������ �� �����, ���� ������� � ��������� ������� �� �����������

        if (next_node->value == 9) {//���� ��������� ������ ����� �������� ���������
            next_node->value = 0;
            next_node = next_node->next;// ����������� �� ����� ������
            continue;
        }

        next_node->value += 1;
        break;
    }
    if (next_node->value == 0) { // ���� ������ ����� �������������
        Big_int.push_back(1);
    }

}


NaturalNumber& NaturalNumber::ADD_NN_N(const NaturalNumber& other) {

    Node* next_node1 = Big_int.get_first(); //�������� �� ����� �� ��������� ������ ������� �����
    Node* next_node2 = other.Big_int.get_first();//�������� �� ����� �� ��������� ������ ������� �����
    int point = 0; //����� ��������� ���� �������, ���� ����� ���� ������ �� ������� ������ �������

    while ((next_node1->next != nullptr) && (next_node2->next != nullptr)) {
        int num1 = next_node1->value; // �������� ���������������� ������� ������� �����
        int num2 = next_node2->value + point; // �������� ���������������� ������� ������� ����� (���� ������� �� ����������� �������, ���� ��� ����)
        if (num1 + num2 >= 10) { // ���� ����� ������� �� ������� ������ �������
            num1 += num2; // �������� �������� ���� �����
            num1 -= 10; // ��������� ������� �������
            point = 1; // ���������� ������� ������� ��� ��������� �������
        }
        else { // ���� ����� �� ������� �� ������� ������ �������
            num1 += num2; // �������� �������� ���� �����
            point = 0; // ��������, ��� ��������� ������ �� ������� ������� �� ����� �������
        }
        next_node1->value = num1; // �������� �������� ����� ��������
        next_node1 = next_node1->next; // ������� � ��������� ������ ������� �����
        next_node2 = next_node2->next; // ������� � ��������� ������ ������� �����
    }
    if ((point == 1) && (next_node1->next == nullptr)) {
        Big_int.push_back(1);
    }
    return *this;
}

NaturalNumber& NaturalNumber::MUL_ND_N(const char c)
{
    if (c == 0) { // ���� ��������� �� 0
        Big_int.get_first()->next = nullptr; // �������� ��������� ����� �����
        Big_int.get_first()->value = 0; // ����� ���������� 0
    }

    Node* next_node = Big_int.get_first();//�������� �� ����� �� ��������� ������ �����
    int point = 0;// �������� � ���� ��������, ���������� ����� ��������� ����������� �������

    while (next_node != nullptr) { // ������ �� ����� �����
        if ((next_node->value *= c)+point > 10) { //���� ������������ ������� �� ������� ������ �������
            int new_point = ((next_node->value *= c) + point) / 10; //��������, ��������� �� ������� ������ �������
            next_node->value = (next_node->value * c) + point - new_point*10; //����� �������� �������
            point = new_point; // ����� �������� point
        }
        else {// ���� ������������ �� ������� �� ������� ������ �������
            next_node->value = (next_node->value * c) + point;//����� �������� �������
            point = 0;//� ��������� ������ �� ��������� ������� �� �����������
        }
        next_node = next_node->next;//����� �� ��������� ������
    }
    if (point > 0) {//���� ������ ����� ������������ ����������
        Big_int.push_back(point);//��������� �������
    }
    return *this;
}

NaturalNumber& NaturalNumber::SUB_NN_N(const NaturalNumber& num)
{
    int point = 0; // ���� ��������� ������ �� ������� ������ �������, ������� ����� ���� ����� �� ����������

    Node* next_node1 = Big_int.get_first(); // �������� �� ����� �� ��������� ������ ������� �����
    Node* next_node2 = num.Big_int.get_first();//�������� �� ����� �� ��������� ������ ������� �����

    while (next_node2->next!=nullptr) {

        int num1 = next_node1->value; //�������� i-�� ������� ������� �����
        int num2 = next_node2->value + point; //�������� i-�� ������� ������� �����

        if (num1 < num2) { //���� �������� i-�� ������� ������� ����� ������ �������
            num1 += 10; //������ ������� ����� �������� 10 �� ����������
            num1 -= num2; //��������� ��������
            point = 1; //����� ����������� � ���������� ��������� �� ������ ����� �������
        }
        else {
            num1 -= num2; //���� �������� i-�� ������� ������� ����� ����� ��� ������
            point = 0;
        }

        next_node1->value = num1; //���������� ��������

        next_node1 = next_node1->next;//����� �� ��������� ������ ������� �����
        next_node2 = next_node2->next; //����� �� ��������� ������ ������� �����

    }
    if (point == 1) {//���� �������� �������, ������� ���� ������� �� ������� ��������
        while (next_node1->value == 0) { //�����, ���� �� �������� �� �������� �� 0 �����
            next_node1->value = 9;
            next_node1=next_node1->next;
        }
        next_node1->value -= 1; //��������� �������
    }
    
    //Node* check_node = Big_int.get_last();
    //for (int j = 0; j < size1; j++) {
    //    if (check_node->value != 0) {
    //       break;                         ////�������� ���������� ����� ����� �������, ���� �������� prev
    //   }
    //   if (check_node->value == 0) {
    //        check_node->prev = nullptr;
      //  }
    //}
    return *this;
}

NaturalNumber& NaturalNumber::MUL_Nk_N(const NaturalNumber& k)
{
    Node* next_node = k.Big_int.get_first(); // �������� �� ����� �� ��������� ������ ����� k

    while (1) {
        Big_int.push_front(0);
        next_node->value -= 1;
        if (next_node->value == 0) {
            if (next_node->next == nullptr) {
                break;
            }
            next_node=next_node->next;
        }
    }
    return *this;
}
