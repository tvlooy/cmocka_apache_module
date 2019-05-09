/* Required headers from Apache httpd */
#include "http_protocol.h"
#include "http_log.h"

/* Prototypes */
static void hello_register_hooks(apr_pool_t *pool);
static int hello_request_handler(request_rec *request, int lookup_uri);

/* The main config structure */
AP_DECLARE_MODULE(hosted_tools_auth) = {
    STANDARD20_MODULE_STUFF,
    NULL,                      /* Per-directory configuration handler */
    NULL,                      /* Merge handler for per-directory configurations */
    NULL,                      /* Per-server configuration handler */
    NULL,                      /* Merge handler for per-server configurations */
    NULL,                      /* Any directives we may have for httpd */
    hello_register_hooks       /* Our hook registering function */
};

/* Add hooks to the httpd process */
static void hello_register_hooks(apr_pool_t *pool)
{
    /* Hook the request handler */
    ap_hook_quick_handler(hello_request_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* Request handler hook */
static int hello_request_handler(request_rec *request, int lookup_uri)
{
    ap_rprintf(request, "Hello world!");

    return OK;
}
