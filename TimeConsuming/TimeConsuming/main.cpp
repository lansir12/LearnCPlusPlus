#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>


using namespace std;

void WriteTXTFile_C()
{
    FILE* fp = fopen("c.txt", "wt");
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            fputc('C', fp);
            fputs("Hello, world!\n", fp);
        }
    }
    fclose(fp);
}

void ReadTXTFile_C()
{
    FILE* fp = fopen("c.txt", "rt");
    char str[15];
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            fgetc(fp);
            fgets(str, 15, fp);
        }
    }
    fclose(fp);
}

void WriteBINFile_C()
{
    FILE* fp = fopen("c.bin", "wb");
    char* str = "CHello, world!\n";
    int len = strlen(str);

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            fwrite(str, 1, len, fp);
        }
    }
    fclose(fp);
}

void ReadBINFile_C()
{
    FILE* fp = fopen("c.bin", "rb");
    char str[16];

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            fread(str, 1, 16, fp);
        }
    }
    fclose(fp);
}

void WriteTXTFile_CPlus()
{
    fstream file;
    file.open("cp.txt", ios::in | ios::out | ios::trunc);//ע��ios::in������ios::in | ios::out���ַ�ʽ���ļ�������ʱ��ִ��д���������Ὠ���ļ���

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            file.put('C');
            file << "Hello, world!\n";
        }
    }
    file.close();
}

void ReadTXTFile_CPlus()
{
    fstream file;
    file.open("cp.txt", ios::in | ios::out);
    char str[15];

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            file.get(str, 15);
        }
    }
    file.close();
}

void WriteBINFile_CPlus()
{
    fstream file;
    file.open("cp.bin", ios::in | ios::out | ios::trunc | ios::binary);
    char* str = "CHello, world!\n";
    int len = strlen(str);

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            file.write(str, len);
        }
    }
    file.close();
}

void ReadBINFile_CPlus()
{
    fstream file;
    file.open("cp.bin", ios::in | ios::out | ios::binary);
    char str[16];

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            file.read(str, 16);
        }
    }
    file.close();
}

int main()
{
    DWORD start, end;
    start = GetTickCount();
    WriteTXTFile_C();
    end = GetTickCount();
    printf("C����д�ı��ļ���������ʱ��Ϊ��%d ms\n", end - start);
    start = GetTickCount();
    WriteTXTFile_CPlus();
    end = GetTickCount();
    cout << "C++д�ı��ļ���������ʱ��Ϊ��" << end - start << " ms" << endl;

    cout << endl;

    start = GetTickCount();
    ReadTXTFile_C();
    end = GetTickCount();
    printf("C���Զ��ı��ļ���������ʱ��Ϊ��%d ms\n", end - start);
    start = GetTickCount();
    ReadTXTFile_CPlus();
    end = GetTickCount();
    cout << "C++���ı��ļ���������ʱ��Ϊ��" << end - start << " ms" << endl;

    cout << endl;

    start = GetTickCount();
    WriteBINFile_C();
    end = GetTickCount();
    printf("C����д�������ļ���������ʱ��Ϊ��%d ms\n", end - start);
    start = GetTickCount();
    WriteBINFile_CPlus();
    end = GetTickCount();
    cout << "C++д�������ļ���������ʱ��Ϊ��" << end - start << " ms" << endl;

    cout << endl;

    start = GetTickCount();
    ReadBINFile_C();
    end = GetTickCount();
    printf("C���Զ��������ļ���������ʱ��Ϊ��%d ms\n", end - start);
    start = GetTickCount();
    ReadBINFile_CPlus();
    end = GetTickCount();
    cout << "C++���������ļ���������ʱ��Ϊ��" << end - start << " ms" << endl;
}