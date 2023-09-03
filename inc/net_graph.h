#ifndef _NET_GRAPH_H_
#define _NET_GRAPH_H_

#include "glthread.h"

const uint8_t kMaxTopoName = 32;

struct net_graph {
  char topology_name[kMaxTopoName];
  GlThreads::glthread_t node_list;
};

#endif