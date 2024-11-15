#include "test.h"
#include "unity.h"
#include "serv_cli_fifo.h"
#include <pthread.h>
#include <sys/stat.h>
void setUp(void){ }
void tearDown(void) {} 


int arr[4]= {3,2,1,0};
void* server_thread_h(void* arg){
  test_serveur(4,arr);
  return NULL; 
}
void* client1_thread_h(void* arg){
  test_client(4,arr);
  return NULL; 
}
void* client2_thread_h(void* arg){
  test_client(4,arr);
  return NULL; 
}
void test_server_client_communication() {
    pthread_t server_tid, client_tid;

    pthread_create(&server_tid, NULL, server_thread_h, NULL);
    pthread_create(&client_tid, NULL, client1_thread_h, NULL);

    pthread_join(server_tid, NULL);
    pthread_join(client_tid, NULL);

}
int main(){ 
    UNITY_BEGIN(); 
    RUN_TEST(test_server_client_communication);
    return UNITY_END(); 
}
