#include "../../headers/NaturalNumber.h"
#include <iostream>

Compare NaturalNumber::COM_NN_D(const NaturalNumber& other) const
{
    int k1 = Big_int.get_size();
    int k2 = other.Big_int.get_size(); // ���������� ���� (������) �� ������ �����

    if (k1 > k2) { //���� ������ ������
        return GREATER;
    }
    if (k1 < k2) { // ���� ������ ������
        return LESS;
    }
    if (k1 == k2) { // ���� ������� ������

        int num1 = Big_int.get_last()->value; //������ ����� ������� �����
        int num2 = other.Big_int.get_last()->value;//������ ����� ������� �����

        if (num1 > num2) { //��������� ���� ������� ��������
            return GREATER;
        }
        if (num1 < num2) {
            return LESS;
        }

        int i = 1;

        Node* next_node1 = Big_int.get_last()->next; //����� �� ��������� ������ ������� �����
        Node* next_node2 = other.Big_int.get_last()->next;//����� �� ��������� ������ ������� �����

        while (i < k1) { //���� ��� ��������� ���� �������� ����� �����

            next_node1 = next_node1->next;//����� �� ��������� ������ ������� �����
            next_node2 = next_node2->next; //����� �� ��������� ������ ������� �����

            num1 = next_node1->value; //�������� i-�� ������� ������� �����
            num2 = next_node2->value; //�������� i-�� ������� ������� �����

            if (num1 > num2) { //��������� ���� ��������
                return GREATER;
            }
            if (num1 < num2) {
                return LESS;
            }

            i++;
        }
        return EQUAL; //���� ����� �����
    }
}

bool NaturalNumber::NZER_N_B()
{
    if ((Big_int.get_size() == 1) && (Big_int.get_first()->value == 0)) {// �������� ����� �� 0
        return false; // ���� ����� ����� 0, �� false
    }

    return true;
}

void NaturalNumber::ADD_1N_N()
{
    if (Big_int.get_first() ->value == 9) { // ���� ��������� ����� ������ ����� �� ������� ������ ������� 

        Big_int.get_first()->value = 0;
        Node* next_node = Big_int.get_first();

        for (int i = 1; i < Big_int.get_size(); i++) { // ������ �� �����, ���� ������� � ��������� ������� �� �����������
            next_node = next_node->next;// ����������� �� ����� ������
            if (next_node->value == 9) {//���� ��������� ������ ����� �������� ���������
                next_node->value = 0;
                continue;
            }
            next_node->value += 1;
            break;
        }
        if (next_node->value == 0) { // ���� ������ ����� �������������
            Big_int.push_back(1);
        }
    }
    else { // ����������� ����������� �������
        Big_int.get_first()->value += 1;
    }
}

NaturalNumber& NaturalNumber::ADD_NN_N(const NaturalNumber& other) {

    Node* next_node1 = Big_int.get_first(); //�������� �� ����� �� ��������� ������ ������� �����
    Node* next_node2 = other.Big_int.get_first();//�������� �� ����� �� ��������� ������ ������� �����
    int point = 0; //����� ��������� ���� �������, ���� ����� ���� ������ �� ������� ������ �������

    for (int i = 0; i < other.Big_int.get_size(); i++) {
        int num1 = next_node1->value;
        int num2 = next_node2->value + point;
        if (num1 < num2) {
            num1 += num2;
            num1 -= 10;
            point = 1;
        }
        else {
            num1 += num2;
            point = 0;
        }
        next_node1->value = num1;
        next_node1->next;
        next_node2->next;
    }
    if ((point == 1) && (next_node1->next == nullptr)) {
        Big_int.push_back(1);
    }
}

NaturalNumber& NaturalNumber::MUL_ND_N(const char c)
{
    if (c == 0) { // ���� ��������� �� 0
        Big_int.get_first()->next = nullptr; // �������� ��������� ����� �����
        Big_int.get_first()->value = 0; // ����� ���������� 0
    }
    if (Big_int.get_first()->value * c >= 10) { // ���� ��������� ��������� ����� ��� ���������� �����

        int desatok = (Big_int.get_first()->value * c) / 10; // ������� �� ���������
        Big_int.get_first()->value = (Big_int.get_first()->value * c) - (desatok * 10); // ������ ��������� �����

        if (Big_int.get_size() > 1) { //���� ����� �� �����������
            Node* next_node = Big_int.get_first()->next;//��������� ���������� �������
            if (next_node->value + desatok > 10) { // ���� ����� ������ � ����� ����� � ������� ������������ ��� ���������� �����

                next_node->value = (next_node->value + desatok - 10); // ����� �������� ������ � ����� �����

                if (Big_int.get_size() > 2) { // ���� ����� ������ 99
                    for (int i = 2; i < Big_int.get_size(); i++) { // ������ �� �����, ���� ������� � ��������� ������� �� �����������
                        next_node->next;
                        if (next_node->value == 9) {
                            next_node->value = 0;
                            continue;
                        }
                        next_node->value += 1;
                        break;
                    }
                    if (next_node->value == 0) { // ���� ������ ����� �������������
                        Big_int.push_back(1);
                    }
                }
                else { // ����������� ����� ����������� ������ �����
                    Big_int.push_front(1);
                }
            }
            else { // ���������� ����� �� ������ ����� �����������
                next_node->value += desatok;
            }
        }
        else { // ���������� ����� ���������� ����������
            Big_int.push_back(desatok);
        }
    }       
    else {
        Big_int.get_first()->value *= c;
    }
}

NaturalNumber& NaturalNumber::SUB_NN_N(const NaturalNumber& num)
{
    int size1 = Big_int.get_size(); // ������ ������� �����
    int size2 = num.Big_int.get_size(); // ������ ������� �����

    int point = 0; // ���� ��������� ������ �� ������� ������ �������, ������� ����� ���� ����� �� ���������
    int i = 1;

    int num1 = Big_int.get_first()->value; //�������� ������� ������� ������� �����
    int num2 = num.Big_int.get_first()->value; //�������� ������� ������� ������� �����

    if (num1 < num2) { //���� �������� ������� ������� ������� ����� ������ �������
        num1 += 10; //������ ������� ����� �������� 10 �� ���������
        num1 -= num2; //��������� ��������
        point = 1; //����� ����������� � ���������� ��������� �� ������ ����� �������
    }
    else {
        num1 -= num2; //���� �������� ������� ������� ������� ����� ����� ��� ������
        point = 0;
    }

    Big_int.get_first()->value = num1; //���������� ��������

    Node* next_node1 = Big_int.get_first()->next; //����� �� ��������� ������ ������� �����
    Node* next_node2 = num.Big_int.get_first()->next;//����� �� ��������� ������ ������� �����

    while (i < size2) {

        next_node1 = next_node1->next;//����� �� ��������� ������ ������� �����
        next_node2 = next_node2->next; //����� �� ��������� ������ ������� �����

        num1 = next_node1->value; //�������� i-�� ������� ������� �����
        num2 = next_node2->value; //�������� i-�� ������� ������� �����

        if (num1 < num2) { //���� �������� i-�� ������� ������� ����� ������ �������
            num1 += 10; //������ ������� ����� �������� 10 �� ���������
            num1 -= num2; //��������� ��������
            point = 1; //����� ����������� � ���������� ��������� �� ������ ����� �������
        }
        else {
            num1 -= num2; //���� �������� i-�� ������� ������� ����� ����� ��� ������
            point = 0;
        }

        next_node1->value = num1; //���������� ��������

        i++;
    }
    next_node1 = next_node1->next;//����� �� ��������� ������ ������� �����
    if ((point == 1) && (next_node1->value == 0)) {//���� �������� �������, ������� ���� ������� �� ������� ��������, �� ��� 0
        while (next_node1->value != 0) { //�����, ���� �� �������� �� �������� �� 0 �����
            next_node1->value = 9;
            next_node1->next;
        }
        point = 0;
        next_node1->value -= 1; //��������� �������
    }
    if (point == 1) {//���� �������� �������, ������� ���� ������� �� ������� ��������, ��� ���� ��� �� 0
        next_node1->value -= 1;
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
}
    
NaturalNumber& NaturalNumber::MUL_Nk_N(const NaturalNumber& k)
{
    if ((Big_int.get_size() != 1) && (Big_int.get_first()->value != 0)) {
        if (k.Big_int.get_first()->value != 1) {
            for (int i = 0; i < k.Big_int.get_size(); i++) {
                Big_int.push_front(0);
            }
        }
    }
}