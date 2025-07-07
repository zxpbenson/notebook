# 各章节源代码文件名
CH03 = 03_02 03_03 03_04 03_05 03_06 03_07 03_08 03_09
CH07 = 07_01 07_02 07_03 07_04 07_05 07_06 07_07 07_08 07_09
CH08 = 08_01 08_02 08_03 08_04 08_05 08_10 08_11 08_12 08_14 08_15 08_16 08_17 08_18 08_19 08_20 08_21 08_22
CH09 = 09_01 09_02 09_03 09_04 09_05 09_06 09_07

# 输出目录定义
BIN_DIR = bin
OBJ_DIR = obj

CH03_BINS = $(addprefix $(BIN_DIR)/ch03/, $(CH03))
CH07_BINS = $(addprefix $(BIN_DIR)/ch07/, $(CH07))
CH08_BINS = $(addprefix $(BIN_DIR)/ch08/, $(CH08))
CH09_BINS = $(addprefix $(BIN_DIR)/ch09/, $(CH09))

ALL_BINS = $(CH03_BINS) $(CH07_BINS) $(CH08_BINS) $(CH09_BINS)

# 编译器设置
CC = gcc
CFLAGS = -Wall -Wno-implicit-int

# 默认目标
all: $(ALL_BINS)

# 03章示例
$(BIN_DIR)/ch03/%: ch03/%.c | $(BIN_DIR)/ch03
	$(CC) $(CFLAGS) $< -o $@

# 07章示例
$(BIN_DIR)/ch07/%: ch07/%.c | $(BIN_DIR)/ch07
	$(CC) $(CFLAGS) $< -o $@

# 08章普通示例
$(BIN_DIR)/ch08/%: ch08/%.c | $(BIN_DIR)/ch08
	$(CC) $(CFLAGS) $< -o $@

# 09章示例
$(BIN_DIR)/ch09/%: ch09/%.c | $(BIN_DIR)/ch09
	$(CC) $(CFLAGS) $< -o $@

# 特殊多文件示例（08_21）
$(BIN_DIR)/ch08/08_21: $(OBJ_DIR)/ch08/08_21_1.o $(OBJ_DIR)/ch08/08_21_2.o | $(BIN_DIR)/ch08
	$(CC) $(CFLAGS) $^ -o $@

# 特殊多文件示例（08_22）
$(BIN_DIR)/ch08/08_22: \
	$(OBJ_DIR)/ch08/08_22_1.o \
	$(OBJ_DIR)/ch08/08_22_2.o \
	$(OBJ_DIR)/ch08/08_22_3.o \
	$(OBJ_DIR)/ch08/08_22_4.o | $(BIN_DIR)/ch08
	$(CC) $(CFLAGS) $^ -o $@

# 多文件 .o 文件的编译规则，存放在 obj/ch08/
$(OBJ_DIR)/ch08/%.o: ch08/%.c | $(OBJ_DIR)/ch08
	$(CC) $(CFLAGS) -c $< -o $@

# 创建各级目录
$(BIN_DIR)/ch03 \
$(BIN_DIR)/ch07 \
$(BIN_DIR)/ch08 \
$(BIN_DIR)/ch09 \
$(OBJ_DIR)/ch08:
	mkdir -p $@

# 清理目标
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: all clean
