#ifndef _GLTHREAD_H_
#define _GLTHREAD_H_

#include <cstddef>
#include <cstdint>

class GlThreads final {
 public:
  GlThreads() = default;
  ~GlThreads() = default;

  struct glthread_node_t {
    glthread_node_t *left;
    glthread_node_t *right;
  };

  struct glthread_t {
    glthread_node_t *head;
    std::size_t offset;
  };

  void Init(glthread_t *glthread, size_t offset);
  void Insert(glthread_t *lst, glthread_node_t *glnode);
  void Remove(glthread_t *lst, glthread_node_t *glnode);

 private:
  void InsertNext(glthread_node_t *curr_node, glthread_node_t *new_node);
  void RemoveNode(glthread_node_t *glnode);
};

#endif