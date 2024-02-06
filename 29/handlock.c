
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct __locked_node
{
    int val;
    locked_node* next;
    pthread_mutex_t lock;
} locked_node;

typedef struct __locked_linked
{
    locked_node* head;
    locked_node* tail;
} locked_list;

// void LockedListGetNext(locked_node** cur)
// {
//     pthread_mutex_unlock(&(*cur)->lock);
//     if(&(*cur)->next != NULL)
//     {
//         *cur = &(*cur)->next;
//         pthread_mutex_lock(&(*cur)->lock);
//     }
//     else
//     {
//         *cur = NULL;
//     }
// }

locked_node* LockedListFind(locked_node* cur, int req)
{
    while(cur != NULL)
    {
        pthread_mutex_lock(&cur->lock);
        if(cur->val == req)
        {
            return cur;
        }
        pthread_mutex_unlock(&cur->lock);
        cur = cur->next;
    }
    return NULL;
}

void* worker(void* args)
{
    
}

int main(int argc, char* argv[])
{

}
