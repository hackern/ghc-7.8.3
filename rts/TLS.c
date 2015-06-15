#include "Rts.h"
#include "TLS.h"

static volatile int tls_next_key = 0;
StgClosure * tls_default_slots[MAX_TLS_SLOTS];

int newTLSKeyHelper(StgClosure *d) {
  int key;
  key = tls_next_key++;
  tls_default_slots[key] = d;
  ASSERT(tls_next_key < MAX_TLS_SLOTS);
  return key;
}
