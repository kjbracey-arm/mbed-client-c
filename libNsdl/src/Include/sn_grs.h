/*
 * GRS.h
 *
 *  Created on: 2.8.2011
 *      Author: Tero
 */

#ifndef GRS_H_
#define GRS_H_


#endif /* GRS_H_ */

#define SN_GRS_VERSION	                	0x0101

#ifndef SN_NSDL_HAVE_HTTP_CAPABILITY
#define SN_NSDL_HAVE_HTTP_CAPABILITY		0
#endif

#ifndef SN_NSDL_HAVE_HTTPS_CAPABILITY
#define SN_NSDL_HAVE_HTTPS_CAPABILITY		0
#endif

#ifndef SN_NSDL_HAVE_COAP_CAPABILITY
#define SN_NSDL_HAVE_COAP_CAPABILITY		1
#endif

#define SN_GRS_RESOURCE_ALREADY_EXISTS	-2
#define SN_GRS_INVALID_PATH 			-3
#define SN_GRS_LIST_ADDING_FAILURE		-4
#define SN_GRS_RESOURCE_UPDATED		-5

#define ACCESS_DENIED			-6

#define SN_GRS_DELETE_METHOD	0
#define SN_GRS_SEARCH_METHOD	1

#define SN_GRS_DEFAULT_ACCESS	0x0F


/***** Structs *****/

typedef struct sn_grs_version_
{
	uint8_t major_version;
	uint8_t minor_version;
	uint8_t build;
}sn_grs_version_s;



/***** Function prototypes *****/
/**
 *	\fn extern int8_t sn_grs_init	(uint8_t (*sn_grs_tx_callback_ptr)(sn_nsdl_capab_e , uint8_t *, uint16_t,
 *									sn_nsdl_addr_s *), uint8_t (*sn_grs_rx_callback_ptr)(sn_coap_hdr_s *, sn_nsdl_addr_s *),
 *									sn_grs_mem_s *sn_memory)
 *
 *  \brief GRS library initialize function.
 *
 *	This function initializes GRS, CoAP and HTTP libraries.
 *
 *	\param 	sn_grs_tx_callback 		A function pointer to a transmit callback function.
 *	\param  *sn_grs_rx_callback_ptr A function pointer to a receiving callback function. If received packet is not for GRS, it will be passed to
 *									upper level (NSDL) to be proceed.
 *	\param 	sn_memory 				A pointer to a structure containing the platform specific functions for memory allocation and free.
 *
 *	\return success = 0, failure = -1
 *
*/
extern int8_t sn_grs_init	(uint8_t (*sn_grs_tx_callback_ptr)(sn_nsdl_capab_e , uint8_t *, uint16_t,
		sn_nsdl_addr_s *), int8_t (*sn_grs_rx_callback_ptr)(sn_coap_hdr_s *, sn_nsdl_addr_s *), sn_nsdl_mem_s *sn_memory);
extern int8_t sn_grs_exec(uint32_t time);
extern sn_grs_resource_list_s *sn_grs_list_resource(uint16_t pathlen, uint8_t *path);
extern sn_nsdl_resource_info_s *sn_grs_get_first_resource(void);
extern sn_nsdl_resource_info_s *sn_grs_get_next_resource(void);
extern sn_nsdl_resource_info_s *sn_grs_get_resource(uint16_t pathlen, uint8_t *path);
extern int8_t sn_grs_delete_resource(uint16_t pathlen, uint8_t *path);
extern int8_t sn_grs_update_resource(sn_nsdl_resource_info_s *res);
/**
 * \fn 	extern int8_t sn_grs_create_resource(sn_grs_resource_info_t *res)
 *
 * \brief Resource creating function.
 *
 *	Used to create a static or dynamic HTTP(S) or CoAP resource.
 *
 *	\param 	*res	Pointer to a structure of type sn_grs_resource_info_t that contains the information
 *					about the resource.
 *
 *	\return 		 0 success
 *					-1 Resource already exists
 *					-2 Invalid path
 *					-3 List adding failure
*/
extern int8_t sn_grs_create_resource(sn_nsdl_resource_info_s *res);
extern int8_t sn_grs_process_http(uint8_t *packet, uint16_t *packet_len, sn_nsdl_addr_s *src);
extern int8_t sn_grs_process_coap(uint8_t *packet, uint16_t packet_len, sn_nsdl_addr_s *src);
extern int16_t sn_grs_get_capability(void);
extern uint32_t sn_grs_get_version(void);
extern int8_t sn_grs_send_coap_message(sn_nsdl_addr_s *address_ptr, sn_coap_hdr_s *coap_hdr_ptr);

extern int8_t sn_grs_destroy(void);






