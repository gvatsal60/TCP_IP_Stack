#include "glthread.h"
using namespace std;

/**
 * @brief
 * @param glthread
 * @param offset
 */
void GlThreads::Init(glthread_t *glthread, size_t offset = 0) {
  glthread->head = nullptr;
  glthread->offset = offset;
}

/**
 * @brief
 * @param lst
 * @param glnode
 */
void GlThreads::Insert(glthread_t *lst, glthread_node_t *glnode) {
  glnode->left = nullptr;
  glnode->right = nullptr;

  /* Check that head of the node is empty */
  if (!lst->head) {
    lst->head = glnode;
    return;
  }

  glthread_node_t *head = lst->head;
  InsertNext(glnode, head);
  lst->head = glnode;
}

/**
 * @brief
 * @param curr_node
 * @param new_node
 */
void GlThreads::InsertNext(glthread_node_t *curr_node, glthread_node_t *new_node) {
  if (!curr_node->right) {
    curr_node->right = new_node;
    curr_node->left = curr_node;
    return;
  }

  glthread_node_t *temp = curr_node->right;
  curr_node->right = new_node;
  new_node->left = curr_node;
  new_node->right = temp;
  temp->left = new_node;
}

/**
 * @brief
 * @param lst
 * @param glnode
 */
void GlThreads::Remove(glthread_t *lst, glthread_node_t *glnode) {
  glthread_node_t *head = lst->head;
  /* If the node being removed is the head node itself, then update the head */
  if (head == glnode) {
    lst->head = head->right;
  }
  RemoveNode(glnode);
}

/**
 * @brief
 * @param glnode
 */
void GlThreads::RemoveNode(glthread_node_t *glnode) {
  if (!glnode->left) {
    if (glnode->right) {
      glnode->right->left = nullptr;
      glnode->right = 0;
      return;
    }
    return;
  }
  if (!glnode->right) {
    glnode->left->right = nullptr;
    glnode->left = nullptr;
    return;
  }

  glnode->left->right = glnode->right;
  glnode->right->left = glnode->left;
  glnode->left = 0;
  glnode->right = 0;
}
