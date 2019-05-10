/* Required headers from Apache httpd */
#include "http_protocol.h"
#include "http_log.h"

/* Prototypes */
static void hello_register_hooks(apr_pool_t *pool);
static int hello_request_handler(request_rec *request, int lookup_uri);
