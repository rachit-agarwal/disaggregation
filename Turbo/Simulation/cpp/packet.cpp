#include "packet.h"


Packet::Packet(double sending_time, Flow *flow, uint32_t seq_no, uint32_t pf_priority,
  uint32_t size, Host *src, Host *dst)
{
  this->sending_time = sending_time;
  this->flow = flow;
  this->seq_no = seq_no;
  this->pf_priority = pf_priority;
  this->size = size;
  this->src = src;
  this->dst = dst;

  this->type = NORMAL_PACKET;
}


Ack::Ack(Flow *flow, uint32_t seq_no_acked, uint32_t sack_bytes,
  uint32_t size,
  Host* src, Host *dst)
  : Packet(0, flow, seq_no_acked, 0, size, src, dst)
{
  this->type = ACK_PACKET;
  this->sack_bytes = sack_bytes;
}
Probe::Probe(Flow *flow, uint32_t probe_priority,
             uint32_t probe_id, bool direction,
             uint32_t size,
             Host *src, Host *dst)
             : Packet (0, flow, 0, 0, size, src, dst)
{
  this->type = PROBE_PACKET;
  this->pf_priority = probe_priority;
  this->probe_id = probe_id;
  this->direction = direction;
}
