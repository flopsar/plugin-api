/*
 * Copyright 2012-present Flopsar Technology Sp. z o.o.
 *
 */

#ifndef PLUGIN_API_H
#define PLUGIN_API_H

#ifdef __cplusplus
extern "C" {
#endif


/*
 * Main plugin structure.
 */
typedef struct Plugin Plugin;



/*
 * This function is called right after the plugin is loaded.
 * All the plugins hooks must be registered in this function.
 * Every plugin must implement this function.
 * @param p Pointer to a structure which represents the plugin. This pointer
 * is provided by the application and it should be passed to other functions if necessary.
 * @param cfg Path to the plugin configuration file. It can be NULL.
 * @return 0 if the plugin has initiated successfully, otherwise returns -1.
 */
int plugin_init(Plugin *p, const char *cfg);



/********************
 * Authentication
 ********************/

typedef enum {
	PLG_AUTH_DENIED = -1,
	PLG_AUTH_GRANTED = 0
} AuthResult;

/*
 * This function is called when the manager attempts to authenticate
 * FDBC connections.
 * @param username
 * @param password
 * @return PLG_AUTH_GRANTED if the connection is granted, otherwise PLG_AUTH_DENIED.
 */
typedef AuthResult (*PluginAuthFunc)(const char *username, const char *password);

/*
 * Call this function to register your authentication plugin.
 */
void plugin_register_auth(Plugin *p, PluginAuthFunc cb);






#ifdef __cplusplus
}
#endif

#endif //PLUGIN_API_H
