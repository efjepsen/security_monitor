#include <crypto_enclave_api.h>
#include <os_util.h>
#include <msgq.h>

int crypto_onetimeauth(unsigned char *out, const unsigned char *in, unsigned long long inlen, const unsigned char *ki) {
  queue_t *q = SHARED_QUEUE;  
  msg_t *m = malloc(sizeof(msg_t));
  m->f = F_ONETIMEAUTH;
  m->args[0] = out;
  m->args[1] = in;
  m->args[2] = inlen;
  m->args[3] = ki;
  int ret = 1;
  while(ret != 0) {
    ret = push(q, msgs[i]);
  }
}

int crypto_onetimeauth_verify(const unsigned char *h,const unsigned char *in,unsigned long long inlen,const unsigned char *k);

int crypto_scalarmult(unsigned char *, const unsigned char *, const unsigned char *);
int crypto_scalarmult_base(unsigned char *, const unsigned char *);

int crypto_stream_salsa20(unsigned char *c, unsigned long long clen, const unsigned char *n, const unsigned char *k);
int crypto_stream_salsa20_xor(unsigned char *c, const unsigned char *m,unsigned long long mlen, const unsigned char *n, const unsigned char *k);

int crypto_stream_salsa208(unsigned char *c, unsigned long long clen, const unsigned char *n, const unsigned char *k);
int crypto_stream_salsa208_xor(unsigned char *c, const unsigned char *m,unsigned long long mlen, const unsigned char *n, const unsigned char *k);

int crypto_stream_salsa2012(unsigned char *c, unsigned long long clen, const unsigned char *n, const unsigned char *k);
int crypto_stream_salsa2012_xor(unsigned char *c, const unsigned char *m,unsigned long long mlen, const unsigned char *n, const unsigned char *k);

int crypto_stream_xsalsa20(unsigned char *c, unsigned long long clen, const unsigned char *n, const unsigned char *k);
int crypto_stream_xsalsa20_xor(unsigned char *c, const unsigned char *m,unsigned long long mlen, const unsigned char *n, const unsigned char *k);

extern int crypto_verify_32(const unsigned char*, const unsigned char*);
extern int crypto_verify_16(const unsigned char*, const unsigned char*);

int crypto_secretbox(unsigned char *c, const unsigned char *m, unsigned long long mlen, const unsigned char *n, const unsigned char *k);
int crypto_secretbox_open(unsigned char *m, const unsigned char *c,unsigned long long clen, const unsigned char *n, const unsigned char *k);

int crypto_box(unsigned char *c, const unsigned char *m, unsigned long long mlen, const unsigned char *n, const unsigned char *pk, const unsigned char *sk);
int crypto_box_open(unsigned char *m, const unsigned char *c, unsigned long long clen, const unsigned char *n, const unsigned char *pk, const unsigned char *sk);