C_SRC := ./src
C_INC := ./Inc
C_TEST := ./test
BUILD_DIR := ./build

SRCS_SERVER = $(C_SRC)/Handlers_Serv.c \
              $(C_SRC)/serveur.c

SRCS_CLIENT = $(C_SRC)/client.c \

SRCS_TEST = $(C_SRC)/src_cli_fifo.c \
			$(C_SRC)/utils.c

OBJS_SERVER = $(patsubst $(C_SRC)/%.c, $(BUILD_DIR)/%.o, $(SRCS_SERVER))
OBJS_CLIENT = $(patsubst $(C_SRC)/%.c, $(BUILD_DIR)/%.o, $(SRCS_CLIENT))
OBJS_TEST = $(patsubst $(C_SRC)/%.c, $(BUILD_DIR)/%.o, $(SRCS_TEST))
OBJS_TEST_INC = $(patsubst $(C_TEST)/%.c, $(BUILD_DIR)/%.o, $(SRCS_TEST))

CC := gcc
CFLAGS := -I$(C_INC)  -g

Server: $(BUILD_DIR) $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER) -o server

Client: $(BUILD_DIR) $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) -o client

$(BUILD_DIR)/%.o: $(C_SRC)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o server client