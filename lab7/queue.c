// $Id: queue.c,v 1.2 2014-02-27 20:04:37-08 - - $

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

typedef struct queue_node queue_node;
struct queue_node {
  queue_item_t item;
  queue_node *link;
};

struct queue {
  queue_node *front;
  queue_node *rear;
};


queue *new_queue (void) {
  queue *nqueue = malloc(sizeof(struct queue));
  assert (nqueue != NULL);
  nqueue->front = NULL;
  nqueue->rear = NULL;
  return nqueue;
}

void free_queue (queue *this) {
  assert (isempty_queue (this));
  free (this);
}

void insert_queue (queue *this, queue_item_t item) {
  queue_node *tmp = malloc(sizeof(struct queue_node));
  tmp->item = item;
  assert(tmp != NULL);
  if(isempty_queue(this)) {
    this->front = tmp;
    this->rear = this->front;
    tmp->link = NULL;
  }
  else{
    this->rear->link = tmp;
    this->rear = tmp;
    tmp->link = NULL;
  }
}

queue_item_t remove_queue (queue *this) {
  assert (! isempty_queue (this));
  queue_node *tmp = this->front;
  queue_item_t string = tmp->item;
  this->front = this->front->link;
  return string;
}

bool isempty_queue (queue *this) {
  return this->front == NULL;
}


