/* Includes ------------------------------------------------------------------*/
#include "udp_client.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);

/* Private functions ---------------------------------------------------------*/

struct udp_pcb *udp_client_connect(uint8_t *_IPADDR,uint16_t _PortNumber)
{
	struct udp_pcb *upcb;
  ip_addr_t DestIPaddr;
  err_t err;
  
  upcb = udp_new();
  
  if (upcb!=NULL)
  {
    IP4_ADDR( &DestIPaddr, _IPADDR[0], _IPADDR[1], _IPADDR[2], _IPADDR[3] );
    
    err= udp_connect(upcb, &DestIPaddr, _PortNumber);
    
    if (err == ERR_OK)
    {
      udp_recv(upcb, udp_receive_callback, NULL);
    }
  }
	return upcb;
}

void udp_client_send(struct udp_pcb *upcb,uint8_t * str , uint16_t _Len)
{
  struct pbuf *p;
	
	if(_Len == 0)
	{
		while(str[_Len] != 0)_Len++;
	}
  
  p = pbuf_alloc(PBUF_TRANSPORT,_Len, PBUF_POOL);
  
  if (p != NULL)
  {
    pbuf_take(p, str, _Len);
    
    udp_send(upcb, p); 
    
    pbuf_free(p);
  }
}

void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
  UDP_client_Recieve(upcb,(uint8_t*)p->payload,p->len,addr,port);
  
  pbuf_free(p);
}

__weak void UDP_client_Recieve(struct udp_pcb *upcb,uint8_t *Buf,uint32_t _Len, const ip_addr_t *addr, u16_t port)
{
	
}

void udp_client_close(struct udp_pcb *upcb)
{
	udp_disconnect(upcb);
}

/*****************************END OF FILE****/
