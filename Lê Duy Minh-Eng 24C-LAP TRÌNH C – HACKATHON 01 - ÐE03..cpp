#include <stdio.h>

int main() {
    int lua_chon;
    int arr[100], n = 0;
    int i, j;
    int temp;
    while (1) {
        printf("-----MENU-----\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong so nguyen to trong mang\n");
        printf("4. Tim gia tri nho thu hai trong mang\n");
        printf("5. Them phan tu vao vi tri ngau nhien\n");
        printf("6. Xoa phan tu tai vi tri\n");
        printf("7. Sap xep mang theo thu tu giam dan (Insertion sort)\n");
        printf("8. Tim kiem phan tu trong mang (Binary search)\n");
        printf("9. Xoa toan bo phan tu trung lap trong mang\n");
        printf("10. Dao nguoc thu tu cac phan tu trong mang\n");
        printf("11. Thoat\n");
        printf("\nLua chon cua ban la: ");
        //gan gia tri cho nguoi dung nhap vao bien lua_chon
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                printf("Moi ban nhap so phan tu cho mang: ");
                scanf("%d", &n);
                
                // them dieu kien de co the yeu cau nguoi dung nhap lai neu nhap sai
                if (n <= 0) {
                    printf("So phan tu khong hop le. Moi nhap lai.\n");
                    break;
                }
                
                for (i = 0; i < n; i++) {
                    printf("Nhap gia tri cho arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
            	//in ra cac gia tri theo dinh dang giong yeu cau
            	// them dieu kien de kiem gtra xem mang dang co phan tu hay khong
            	if(n == 0){
            		printf("mang cua ban hien dang trong, moi ban quay lai 1 de nhap phan tu cho mang\n");
            		
				} else {
					printf("Gia tri cac phan tu trong mang:\n");
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
				}
                break;

            /*case 3:
                */

            case 4:
            	//tim gia tri be thu hai trong mang
                // su dung {} de su dung bien rieng trong case tuan huan trong while
            	//kiem tra dieu kien 
                {
                	if( n == 0) {
                			printf("mang cua ban hien dang trong, moi ban quay lai 1 de nhap phan tu cho mang\n");
					} else {
						int min1 = arr[0], min2 = 1;
                    for (i = 1; i < n; i++) {
                        if (arr[i] < min1) {
                            min2 = min1;
                            min1 = arr[i];
                        } else if (arr[i] < min2 && arr[i] != min1) {
                            min2 = arr[i];
                        }
                    }
                    if (min2 != 1) {
                        printf("Gia tri nho thu hai trong mang: %d\n", min2);
                    } else {
                        printf("Khong co gia tri nho thu hai.\n");
                    }
					}
                }
                break;

            case 5:
            	//them mot phan tu vao mang
            	
                {
                	// mang rong cac phan tu
                	if(n == 0){
                	printf("mang cua ban hien tai dang trong, moi ban quay lai 1 de nhap phan tu\n");
					break;	
					}
					//mang da chua du cac phan tu
					if(n > 100){
						printf("mang cua ban da chua toi da phan tu ban co the next qua buoc 6 de xoa roi quay lai\n");
						break;
					}
					
						int value, position;
                    printf("Nhap gia tri phan tu can them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri can them (0 den %d): ", n);
                    scanf("%d", &position);

                    if (position < 0 || position > n) {
                        printf("Vi tri khong hop le.\n");
                        break;
                    }

                    for (i = n; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = value;
                    n++;
                    printf("Da them phan tu %d vao vi tri %d.\n", value, position);
					}
                    
                
                break;

            case 6:
            	//xoa phan tu tai mot vi tri cu the
                {
                	//neu mang rong thi khong the xoa
                	if(n == 0){
                			printf("mang cua ban hien tai dang trong, moi ban quay lai 1 de nhap phan tu\n");
					} else {
						int position;
                    printf("Nhap vi tri phan tu can xoa (0 den %d): ", n - 1);
                    scanf("%d", &position);

                    if (position < 0 || position >= n) {
                        printf("Vi tri khong hop le.\n");
                        break;
                    }

                    for (i = position; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Da xoa phan tu tai vi tri %d.\n", position);
					}
                }
                break;

            case 7:
            	//sap xep mang theo thu tu giam dan theo cach sap xep Insertion sort
                {
                	// kiem tra dieu kien
                	if(n == 0){
                			printf("mang cua ban hien tai dang trong, moi ban quay lai 1 de nhap phan tu\n");
                			break;
					}
                    if(n == 1){
                    	printf("mang cua ban khong can sap xep khi chi co mot phan tu\n");
                    	break;
					}
                    
                    
                    
                    for (i = 1; i < n; i++) {
                        temp = arr[i];
                        int j = i - 1;
                        while (j >= 0 && arr[j] < temp) {
                            arr[j + 1] = arr[j];
                            j--;
                        }
                        arr[j + 1] = temp;
                    }
                    printf("Mang sau khi sap xep theo thu tu giam dan:\n");
                    for (i = 0; i < n; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 8:
            	// cho nguoi dung nhap vao mot phan tu sau do kiem tra xem phan tu do co ton tai trong mang hay khong
                { 
                    //kiem tra dieu kien 
                    if(n == 0){
                    	printf("mang cua ban hien tai dang trong, moi ban quay lai 1 de nhap phan tu\n");
                    	break;
					}
					
                    int key, left = 0, right = n - 1, mid;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &key);
                    
                    
					

                    while (left <= right) {
                        mid = (left + right) / 2;
                        if (arr[mid] == key) {
                            printf("Phan tu %d da tim thay tai vi tri %d.\n", key, mid);
                            break;
                        } else if (arr[mid] < key) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }

                    if (left > right) {
                        printf("Phan tu %d khong ton tai trong mang.\n", key);
                    }
                }
                break;

            /*case 9:
            	// xoa toan bo phan tu trung lap trong mang va hien thi toan bo phan tu doc nhat co o trong mang
                {
                	 if(n == 0){
                    	printf("mang cua ban hien tai dang trong, moi ban quay lai 1 de nhap phan tu\n");
                    	break;
					}
                }
                break; */

            case 10:
            	// dao nguoc cac phan tu co trong mang
                {
                     if(n == 0){
                    	printf("mang cua ban hien tai dang trong, moi ban quay lai 1 de nhap phan tu\n");
                    	break;
					}
					if(n == 1){
                    	printf("mang cua ban khong the dao khi chi co mot phan tu\n");
                    	break;
					}
					
                    for (i = 0; i < n / 2; i++) {
                        temp = arr[i];
                        arr[i] = arr[n - i - 1];
                        arr[n - i - 1] = temp;
                    }

                    printf("Mang sau khi dao nguoc:\n");
                    for (i = 0; i < n; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 11:
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }//cai nay la cua swich
    } // cai nay la cua while
    //ket thuc chuong trinh
    return 0;
} // cai nay la cua ket thuc

