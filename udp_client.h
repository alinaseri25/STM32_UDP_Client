/* Define to prevent recursive inclusion -------------------------------------*/  
#ifndef __UDP_CLIENT_H__
#define __UDP_CLIENT_H__

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
struct udp_pcb *udp_client_connect(uint8_t *_IPADDR,uint16_t _PortNumber);
void udp_client_send(struct udp_pcb *upcb,uint8_t * str , uint16_t _Len);
void udp_client_close(struct udp_pcb *upcb);
__weak void UDP_client_Recieve(struct udp_pcb *upcb,uint8_t *Buf,uint32_t _Len, const ip_addr_t *addr, u16_t port);

#endif /* __UDP_CLIENT_H__ */
