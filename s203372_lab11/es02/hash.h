#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

typedef struct Client *CLIENT;

CLIENT hashtable_init(int argc, char* argv[], CLIENT client);
void hashtable_uploaddata(int argc, char* argv[], CLIENT client);
void hashtable_filesave(int argc, char* argv[], CLIENT client);

#endif // HASH_H_INCLUDED
