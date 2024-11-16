#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 5

typedef struct product {
    int id;
    char name[100];
    int in;
    float price;
    int sold;
} PRODUCT;

void save_products(PRODUCT* products, int size, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("파일 저장에 실패했습니다.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        if (products[i].id != 0) { // 유효한 데이터만 저장
            fprintf(file, "%d %s %d %.2f %d\n", products[i].id, products[i].name, products[i].in, products[i].price, products[i].sold);
        }
    }
    fclose(file);
    printf("상품 데이터가 파일에 저장되었습니다.\n");
}

void load_products(PRODUCT* products, int* product_count, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 찾을 수 없습니다. 초기 상태로 시작합니다.\n");
        return;
    }
    while (fscanf(file, "%d %s %d %f %d", &products[*product_count].id, products[*product_count].name, 
                  &products[*product_count].in, &products[*product_count].price, &products[*product_count].sold) == 5) {
        (*product_count)++;
    }
    fclose(file);
    printf("파일에서 상품 데이터를 불러왔습니다.\n");
}

void input_product(PRODUCT* products, int* product_count, int size) {
    int id, quantity;
    char name[100];
    float price;
    int index = -1;

    if (*product_count >= size) {
        printf("최대 상품 수를 초과했습니다.\n");
        return;
    }
    printf("상품 ID: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("기존 상품입니다. 수량을 업데이트합니다.\n");
        printf("입고량: ");
        scanf("%d", &quantity);
        products[index].in += quantity;
        printf("판매가격: ");
        scanf("%f", &price);
        products[index].price = price;
    } else {
        printf("새로운 상품입니다. 정보를 입력합니다.\n");
        index = *product_count;
        products[index].id = id;
        (*product_count)++;
        printf("상품명: ");
        scanf("%s", products[index].name);
        printf("입고량: ");
        scanf("%d", &quantity);
        products[index].in = quantity;
        printf("판매가격: ");
        scanf("%f", &price);
        products[index].price = price;
    }
    printf("%s 입고 완료 (현재 재고: %d개)\n", products[index].name, products[index].in);
}

void input_sales(PRODUCT* products, int size) {
    int id, quantity;
    int index = -1;
    printf("상품 ID: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("해당 상품 ID가 없습니다.\n");
        return;
    }
    printf("판매량: ");
    scanf("%d", &quantity);
    if (quantity > products[index].in) {
        printf("재고가 부족합니다.\n");
    } else {
        products[index].sold += quantity;
        products[index].in -= quantity;
        printf("%s 판매 완료 (남은 재고: %d개)\n", products[index].name, products[index].in);
    }
}

void individual_status(PRODUCT* products, int size) {
    int id;
    int index = -1;
    printf("상품 ID: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("해당 상품 ID가 없습니다.\n");
        return;
    }
    printf("\n상품명: %s\n", products[index].name);
    printf("재고 수량: %d개\n", products[index].in);
    printf("판매 수량: %d개\n", products[index].sold);
    printf("판매 가격: %.2f원\n", products[index].price);
}

void all_status(PRODUCT* products, int size) {
    float total_sales = 0;
    printf("\n전체 상품 현황:\n");
    for (int i = 0; i < size; i++) {
        if (products[i].id == 0) continue;
        printf("ID %d - %s: 재고 %d개, 판매 %d개, 가격 %.2f원\n", products[i].id, products[i].name, products[i].in, products[i].sold, products[i].price);
        total_sales += products[i].sold * products[i].price;
    }
    printf("총 판매 금액: %.2f원\n", total_sales);
}

int main() {
    PRODUCT products[SIZE] = { 0 };
    int product_count = 0;
    int choice;
    const char* filename = "products.txt";

    load_products(products, &product_count, filename);

    while (1) {
        printf("\n메뉴 선택 (1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_product(products, &product_count, SIZE);
                save_products(products, SIZE, filename);
                break;
            case 2:
                input_sales(products, SIZE);
                save_products(products, SIZE, filename);
                break;
            case 3:
                individual_status(products, SIZE);
                break;
            case 4:
                all_status(products, SIZE);
                break;
            case 5:
                printf("프로그램을 종료합니다.\n");
                save_products(products, SIZE, filename);
                return 0;
            default:
                printf("⚠️ 잘못된 선택입니다.\n");
        }
    }
    return 0;
}
