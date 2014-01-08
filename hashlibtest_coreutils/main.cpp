#include "md5.h"
#include "sha1.h"
#include "sha256.h"
#include "sha512.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <QByteArray>
#include <iostream>

enum hashname {
    hash_md5=0,
    hash_sha1=1,
    hash_sha224=2,
    hash_sha256=3,
    hash_sha384=4,
    hash_sha512=5
};

enum hashlen {
    hashlen_md5=16,
    hashlen_sha1=20,
    hashlen_sha224=28,
    hashlen_sha256=32,
    hashlen_sha384=48,
    hashlen_sha512=64
};

#define teststr "abec"
#define md5_buffer __md5_buffer
#define HASHTEST(NAME) \
    ch_hash[hash_##NAME]=(char*)NAME##_buffer(teststr"\x0a",strlen(teststr)+1,t);\
    hash=QByteArray::fromRawData(ch_hash[hash_##NAME],hashlen_##NAME); \
    std::cout<<"echo \""teststr"\" | "#NAME"sum :"<<std::endl; \
    system("echo \""teststr"\" | "#NAME"sum"); \
    std::cout<<hash.toHex().data()<<std::endl;

int main()
{
    QByteArray hash;
    char t[200];
    char* ch_hash[4];
    //FILE* testfile=fopen("md5.h","r");
    //sha512_stream(testfile,t);
    HASHTEST(md5);
    HASHTEST(sha1);
    HASHTEST(sha224);
    HASHTEST(sha256);
    HASHTEST(sha384);
    HASHTEST(sha512);
    return 0;
}
