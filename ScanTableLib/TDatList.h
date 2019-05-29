#pragma once
#include "TDatLink.h"
#include <iostream>

enum TLinkPos {FIRST, CURRENT, LAST};

#define ListOK       0
#define ListEmpty -101
#define ListNoMem -102
#define ListNoPos -103

class TDatList 
{
protected:
    PTDatLink pFirst;    // ������ �����
    PTDatLink pLast;     // ��������� �����
    PTDatLink pCurrLink; // ������� �����
    PTDatLink pPrevLink; // ����� ����� �������
    PTDatLink pStop;     // �������� ���������, ����������� ����� ������
    int CurrPos;         // ����� �������� ����� (��������� �� 0)
    int ListLen;         // ���������� ������� � ������
protected:  // ������
    PTDatLink GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL);
    void DelLink (PTDatLink pLink);   // �������� �����
public:
    TDatList();
    ~TDatList() { DelList(); }
    // ������
    PTDatValue GetDatValue(TLinkPos mode = CURRENT) const; // ��������
    virtual int IsEmpty() const { return pFirst == pStop; } // ������ ���� ?
    int GetListLength() const { return ListLen; }       // �-�� �������
    // ���������
    int SetCurrentPos(int pos);          // ���������� ������� �����
    int GetCurrentPos() const;       // �������� ����� ���. �����
    virtual int Reset();             // ���������� �� ������ ������
    virtual int IsListEnded() const; // ������ �������� ?
    int GoNext();                    // ����� ������ �������� �����
                // (=1 ����� ���������� GoNext ��� ���������� ����� ������)
    // ������� �������
    virtual void InsFirst(PTDatValue pVal = NULL); // ����� ������
    virtual void InsLast(PTDatValue pVal = NULL); // �������� ���������
    virtual void InsCurrent(PTDatValue pVal = NULL); // ����� �������
    // �������� �������
    virtual void DelFirst();    // ������� ������ �����
    virtual void DelCurrent();    // ������� ������� �����
    virtual void DelList();    // ������� ���� ������
};
typedef TDatList *PTDatList;

