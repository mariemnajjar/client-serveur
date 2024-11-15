C_SRC := ./src

C_INC := ./Inc
C_TEST := ./test
BUILD_DIR := ./build

SRCS_SERVER = $(C_SRC)/Handlers_Serv.c \
              $(C_SRC)/serveur.c

SRCS_CLIENT = $(C_SRC)/client.c \
							$(C_SRC)/Handlers_Serv.c 


SRCS_TEST = $(C_TEST)/unity.c \
            $(C_TEST)/tests.c \
            $(C_TEST)/test_client.c \
            $(C_TEST)/test_server.c  


OBJS_SERVER = $(patsubst $(C_SRC)/%.c, $(BUILD_DIR)/%.o, $(SRCS_SERVER))
OBJS_CLIENT = $(patsubst $(C_SRC)/%.c, $(BUILD_DIR)/%.o, $(SRCS_CLIENT))
# OBJS_COMON = $(patsubst $(C_SRC)/%.c, $(BUILD_DIR)/%.o, $(SRCS_C))
OBJS_TEST = $(patsubst $(C_TEST)/%.c, $(BUILD_DIR)/%.o, $(SRCS_TEST))
# OBJS_TEST_INC = $(patsubst $(C_TEST)/%.c, $(BUILD_DIR)/%.o, $(SRCS_TEST))
OBJS_TEST += $(BUILD_DIR)/Handlers_Serv.o
CC := gcc
CFLAGS := -I$(C_INC)  -g
all:Server Client Test
Server: $(BUILD_DIR) $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER) -o server

Client: $(BUILD_DIR) $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) -o client
Test: $(BUILD_DIR) $(OBJS_TEST)
	$(CC) $(OBJS_TEST) -o $@


$(BUILD_DIR)/%.o: $(C_TEST)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(C_SRC)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o server client
