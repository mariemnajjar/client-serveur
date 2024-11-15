RealisationTP unix:<br> 
Create a Client/Server communication using named pipes

![pic](./TP_unix.png)


## Testing
i used Unity framework for testing.<br> 
i created 2 function `test_server` & `test_client`, to test the communication.<br>
- The client will send an N integer to fifo1 <br>
- The server will respond in FiFo2 with N elements <br>
- So i prefixed the N to be 4 and the N elements to be `{3,2,1,0}`<br>
this is my test case, the picture bellow shows the result `Test is success`<br>

![pic](./Test_Unix.png)
