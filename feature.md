[TOC]

### ��ȡ��ά��

```assembly
621C10FA    68 AC2B0000     push 0x2BAC
621C10FF    C645 FC 00      mov byte ptr ss:[ebp-0x4],0x0
621C1103    E8 C83D0C00     call WeChatWi.62284ED0
621C1108    8D4D 0C         lea ecx,dword ptr ss:[ebp+0xC]		;ָ���ά��ṹ���ָ��
621C110B    E8 30EF2800     call WeChatWi.62450040
621C1110    8B4D F4         mov ecx,dword ptr ss:[ebp-0xC]          
621C1113    64:890D 0000000>mov dword ptr fs:[0],ecx
621C111A    59              pop ecx                                  
621C111B    5F              pop edi                                 
621C111C    5E              pop esi                                  
621C111D    5B              pop ebx                                  
621C111E    8BE5            mov esp,ebp
621C1120    5D              pop ebp                                  
621C1121    C2 1000         retn 0x10
```

```assembly
E8 ???????? 8D4D 0C E8 ???????? 8B4D F4
```

### ��ȡ�����б��Ⱥ�б�

����ܻ�ȡ�����е�Ⱥ����ϵ��

```assembly
623F8937    8D45 08         lea eax,dword ptr ss:[ebp+0x8]
623F893A    C645 FC 01      mov byte ptr ss:[ebp-0x4],0x1
623F893E    8D5E 68         lea ebx,dword ptr ds:[esi+0x68]
623F8941    50              push eax
623F8942    8BCB            mov ecx,ebx
623F8944    E8 E7EAC2FF     call WeChatWi.62027430                    ; ��ȡ�����б�
623F8949    8BF0            mov esi,eax							      ;eax������ÿ��������Ϣ
64DE894B        3B33        cmp esi,dword ptr ds:[ebx]
64DE894D        74 1F       je short WeChatWi.64DE896E
64DE894F        8B46 10     mov eax,dword ptr ds:[esi+0x10]
64DE8952        85C0        test eax,eax
64DE8954        74 06       je short WeChatWi.64DE895C
64DE8956        66:8338 00  cmp word ptr ds:[eax],0x0
64DE895A        75 05       jnz short WeChatWi.64DE8961
64DE895C        B8 047CA665 mov eax,WeChatWi.65A67C04
64DE8961        50          push eax
64DE8962        8D4D 08     lea ecx,dword ptr ss:[ebp+0x8]
64DE8965        E8 B6950500 call WeChatWi.64E41F20					;HOOK����ط� ȡesi������
```

```assembly
8D45 ?? C645 ?? 01 8D5E ?? 50 8BCB E8 ???????? 8BF0
```

���ֻ�ܻ�ȡ�����ֵ�Ⱥ

```assembly
0FDCA902  |.  84C0              test al,al
0FDCA904  |.  0F85 6B020000     jnz WeChatWi.0FDCAB75
0FDCA90A  |.  E8 A156EDFF       call WeChatWi.0FC9FFB0
0FDCA90F  |.  53                push ebx
0FDCA910  |.  E8 FBA70F00       call WeChatWi.0FEC5110                   ;  esi��������ϵ��
0FDCA915  |.  83F8 03           cmp eax,0x3
```

```assembly
84C0 0F85 ???????? E8 ????????  53 E8 ???????? 83F8 03
```

### ������Ϣ

```assembly
616743F8    8B55 CC         mov edx,dword ptr ss:[ebp-0x34]          ; ΢��ID��ָ��
616743FB    8D43 14         lea eax,dword ptr ds:[ebx+0x14]
616743FE    6A 01           push 0x1                                 ; 0x1
61674400    50              push eax                                 ; �Ƿ�@��
61674401    53              push ebx                                 ; ��Ϣ�ı���ָ��
61674402    8D8D E4F7FFFF   lea ecx,dword ptr ss:[ebp-0x81C]         ; 0x81C���ȵĻ�����
61674408    E8 E35C2100     call WeChatWi.6188A0F0                   ; ������Ϣ��call
6167440D    83C4 0C         add esp,0xC
```

```assembly
8B55 ?? 8D43 ?? 6A 01 50 53 8D8D ???????? E8 ???????? 83C4 0C
```

### ���Ͱ�����Ϣʱ��װ���ݽṹ��call

�̳����ҵ�call

```assembly
6055AA2D    50              push eax
6055AA2E    8D8D 10FFFFFF   lea ecx,dword ptr ss:[ebp-0xF0]
6055AA34    E8 E7733E00     call WeChatWi.60941E20
6055AA39    8D85 D4FEFFFF   lea eax,dword ptr ss:[ebp-0x12C]
6055AA3F    50              push eax                                 ; ΢��ID
6055AA40    8D8D 44FFFFFF   lea ecx,dword ptr ss:[ebp-0xBC]          ; 0x10��С�Ļ�����
6055AA46    E8 C5B4FBFF     call WeChatWi.60515F10                   ; ��װ���ݵ�call
6055AA4B    8D8D ACFEFFFF   lea ecx,dword ptr ss:[ebp-0x154]
6055AA51    E8 8A990100     call WeChatWi.605743E0
6055AA56    8D8D D4FEFFFF   lea ecx,dword ptr ss:[ebp-0x12C]
6055AA5C    E8 7F990100     call WeChatWi.605743E0
```

```assembly
50 8D8D ???????? E8 ???????? 8D85 ???????? 50 8D8D ???????? E8 ???????? 8D8D ???????? E8 ???????? 8D8D ???????? E8 ????????
```

�Լ��ҵ�call

```assembly
6055A7CE    56              push esi
6055A7CF    8D85 10FFFFFF   lea eax,dword ptr ss:[ebp-0xF0]
6055A7D5    C645 FC 02      mov byte ptr ss:[ebp-0x4],0x2
6055A7D9    50              push eax
6055A7DA    6A 01           push 0x1
6055A7DC    8D8D C4FEFFFF   lea ecx,dword ptr ss:[ebp-0x13C]
6055A7E2    E8 69E9FFFF     call WeChatWi.60559150
6055A7E7    50              push eax                                 ; ������Ϣ�ĸ�ʽ
6055A7E8    8BCF            mov ecx,edi                              ; ������ݽṹ�Ļ�����
6055A7EA    C645 FC 03      mov byte ptr ss:[ebp-0x4],0x3
6055A7EE    E8 BD3E0000     call WeChatWi.6055E6B0                   ; �Լ��ҵ�call
```

```assembly
56 8D85 ???????? C645 ?? 02 50 6A 01 8D8D ???????? E8 ???????? 50 8BCF C645 ?? 03 E8 ????????
```

### ������Ϣ

```assembly
622E5E8D    50              push eax
622E5E8E    A1 F8D72363     mov eax,dword ptr ds:[0x6323D7F8]
622E5E93    B9 F8D72363     mov ecx,WeChatWi.6323D7F8           ; [esp]��ָ���ڱ�����Ϣ�ṹ��
622E5E98    FF50 08         call dword ptr ds:[eax+0x8]		    ;������Ϣ��call
622E5E9B    8B1D 0CF62463   mov ebx,dword ptr ds:[0x6324F60C]
622E5EA1    F6C3 01         test bl,0x1
```

```assembly
50 A1 ???????? B9 ???????? FF50 08 8B1D ???????? F6C3 01
```

### ѡ����ϵ��

```assembly
61A31EC7    50              push eax
61A31EC8    8BCE            mov ecx,esi
61A31ECA    E8 F1000000     call WeChatWi.61A31FC0
1A31ECF     5E              pop esi
```

```assembly
508BCE E8 ???????? 5E
```

### ����xml��Ƭ

```assembly
61A5B2A7  |>  6A 2A         |push 0x2A                               ;  0x2A
61A5B2A9  |.  8D45 D8       |lea eax,[local.10]
61A5B2AC  |.  8BD6          |mov edx,esi                             ;  wxid
61A5B2AE  |.  6A 00         |push 0x0
61A5B2B0  |.  50            |push eax                                ;  xml����
61A5B2B1  |.  8D8D F4FDFFFF |lea ecx,[local.131]
61A5B2B7  |.  E8 24021800   |call WeChatWi.61BDB4E0                  ;  ����xml��call
61A5B2BC  |.  83C4 0C       |add esp,0xC
```

```assembly
6A 2A 8D45 ?? 8BD6 6A 00 50 8D8D ???????? E8 ???????? 83C4 0C
```

### ����xml����

```assembly
6196D1DD    8D45 DC         lea eax,dword ptr ss:[ebp-0x24]          ; 0x24�Ļ�����
6196D1E0    FFB5 E0FAFFFF   push dword ptr ss:[ebp-0x520]            ; 0x5
6196D1E6    50              push eax
6196D1E7    8D45 BC         lea eax,dword ptr ss:[ebp-0x44]          ; 0x44�Ļ�����
6196D1EA    50              push eax
6196D1EB    8D45 9C         lea eax,dword ptr ss:[ebp-0x64]          ; ���͵�xml����
6196D1EE    50              push eax
6196D1EF    8D45 0C         lea eax,dword ptr ss:[ebp+0xC]           ; �����ߵ�΢��ID
6196D1F2    50              push eax
6196D1F3    8D85 BCFBFFFF   lea eax,dword ptr ss:[ebp-0x444]         ; �����ߵ�΢��ID
6196D1F9    50              push eax
6196D1FA    8D85 84F8FFFF   lea eax,dword ptr ss:[ebp-0x77C]         ; 0x77C������
6196D200    50              push eax
6196D201    E8 8AE7FFFF     call WeChatWi.6196B990					 ;����xml���µ�call
```

```assembly
8D45 ?? FFB5 ???????? 50 8D45 ?? 50 8D45 ?? 50 8D45 ?? 50 8D85 ???????? 50 8D85 ???????? 50 E8 ????????
```

### �����ļ�

```assembly
5071BF32    6A 01           push 0x1
5071BF34    83EC 14         sub esp,0x14
5071BF37    8BCC            mov ecx,esp
5071BF39    8965 D0         mov dword ptr ss:[ebp-0x30],esp
51D2BF3C    6A FF           push -0x1
51D2BF3E    68 047CD052     push WeChatWi.52D07C04
51D2BF43    E8 78593B00     call WeChatWi.520E18C0
51D2BF48    83EC 14         sub esp,0x14
51D2BF4B    C745 FC 0B00000>mov dword ptr ss:[ebp-0x4],0xB           ; ������Բ���д
51D2BF52    8BCC            mov ecx,esp
51D2BF54    8965 C0         mov dword ptr ss:[ebp-0x40],esp
51D2BF57    53              push ebx                                 ; Ҫ���͵��ļ�·��
51D2BF58    E8 A3593B00     call WeChatWi.520E1900
51D2BF5D    83EC 14         sub esp,0x14
51D2BF60    8BCC            mov ecx,esp
51D2BF62    8965 BC         mov dword ptr ss:[ebp-0x44],esp
51D2BF65    FF75 CC         push dword ptr ss:[ebp-0x34]             ; �����ߵ�΢��ID
51D2BF68    E8 93593B00     call WeChatWi.520E1900
51D2BF6D    8D85 A4FBFFFF   lea eax,dword ptr ss:[ebp-0x45C]
51D2BF73    C645 FC 0D      mov byte ptr ss:[ebp-0x4],0xD            ; ������Բ���д
51D2BF77    50              push eax                                 ; 0x45C��С�Ļ�����
51D2BF78    E8 43FBF9FF     call WeChatWi.51CCBAC0                   ; ��Ϸ����ļ�����
51D2BF7D    8BC8            mov ecx,eax
51D2BF7F    C745 FC FFFFFFF>mov dword ptr ss:[ebp-0x4],-0x1
51D2BF86    E8 65BE1600     call WeChatWi.51E97DF0                   ; �����Ƿ����ļ���call һ��Ҫִ��
```

```assembly
6A FF 68 ???????? E8 ???????? 83EC 14 C745 FC 0B000000 8BCC 8965 C0 53 E8 ???????? 83EC 14 8BCC 8965 BC FF75 CC E8 ???????? 8D85 A4FBFFFF C645 FC 0D 50 E8 ???????? 8BC8 C745 FC FFFFFFFF E8 ????????
```

### ����ͼƬ

```assembly
5750BE04  |> \53            |push ebx                                ;  ͼƬ·��; 
5750BE05  |.  FF75 CC       |push dword ptr ss:[ebp-0x34]            ;  ΢��ID�ṹ��
5750BE08  |.  8D85 A4FBFFFF |lea eax,dword ptr ss:[ebp-0x45C]
5750BE0E  |.  50            |push eax                                ;  0x45C��С�Ļ�����
5750BE0F  |.  51            |push ecx                                ;  0
5750BE10  |.  E8 DB59FBFF   |call WeChatWi.574C17F0                  ;  ����ͼƬcall
5750BE15  |.  83C4 04       |add esp,0x4
5750BE18  |.  8BC8          |mov ecx,eax							 ;  eax������Ǿ��
5750BE1A  |.  E8 B1F02100   |call WeChatWi.5772AED0                  ;  ���call����÷���ͼƬ��Ҫ������call
```

```assembly
56 FF75 CC 8D85 A4FBFFFF 50 51 E8 ???????? 83C4 04 8BC8 E8 ????????
```

### �������ݿ�

```assembly
61E589CB    8D45 E8         lea eax,dword ptr ss:[ebp-0x18]
61E589CE    50              push eax                                 ; ���ݿ���Կ�ṹ��
61E589CF    56              push esi                                 ; ���
61E589D0    57              push edi                                 ; Ҫ���ܵ����ݿ�����
61E589D1    E8 5AFAFFFF     call WeChatWi.61E58430                   ; �������ݿ��call
```

```assembly
8D45 ?? 50 56 57 E8 ????????
```

### ��ȡȺ��Ա�б�

```assembly
617A85CF    50              push eax
617A85D0    53              push ebx
617A85D1    E8 5A520B00     call WeChatWi.6185D830              ; �õ����ݿ�ľ��
617A85D6    8BC8            mov ecx,eax
617A85D8    E8 B3C32100     call WeChatWi.619C4990              ; ��ȡ�б�
617A85DD    8D85 8CFEFFFF   lea eax,dword ptr ss:[ebp-0x174]
617A85E3    50              push eax
617A85E4    8D8D 9CFEFFFF   lea ecx,dword ptr ss:[ebp-0x164]
617A85EA    E8 E1452100     call WeChatWi.619BCBD0              ; ��ȡȺ�����б�
617A85EF    83EC 0C         sub esp,0xC
```

```assembly
50 53 E8 ???????? 8BC8 E8 ???????? 8D85 ???????? 50 8D8D ???????? E8 ???????? 83EC 0C 
```

### ����΢��ID��ȡ������Ϣ

```assembly
617A7362    8DBE F80B0000   lea edi,dword ptr ds:[esi+0xBF8]
617A7368    57              push edi                                 ; ��һ�����ѵĸ�����Ϣ
617A7369    83EC 14         sub esp,0x14
617A736C    8D45 08         lea eax,dword ptr ss:[ebp+0x8]           ; ��ǰѡ�е�΢��ID
617A736F    8BCC            mov ecx,esp
617A7371    8965 D4         mov dword ptr ss:[ebp-0x2C],esp
617A7374    50              push eax
617A7375    E8 E63A2800     call WeChatWi.61A2AE60
617A737A    C645 FC 01      mov byte ptr ss:[ebp-0x4],0x1
617A737E    E8 CD4AE5FF     call WeChatWi.615FBE50                   ; ���ؾ��
617A7383    C645 FC 00      mov byte ptr ss:[ebp-0x4],0x0
617A7387    E8 A4F90600     call WeChatWi.61816D30                   ; ��ȡ��������
```

```c++
8DBE ???????? 57 83EC 14 8D45 ?? 8BCC ???? D4 50 E8 ????????
```

### �Ӻ���

```assembly
5F0D5747  |> \83EC 18       sub esp,0x18
5F0D574A  |.  8BCC          mov ecx,esp
5F0D574C  |.  89A5 24FFFFFF mov [local.55],esp
5F0D5752  |.  68 A86CF75F   push WeChatWi.5FF76CA8
5F0D5757  |.  E8 3445F0FF   call WeChatWi.5EFD9C90
62269DCC    83EC 18         sub esp,0x18
62269DCF    C645 FC 03      mov byte ptr ss:[ebp-0x4],0x3
62269DD3    8D86 38030000   lea eax,dword ptr ds:[esi+0x338]
62269DD9    89A5 1CFFFFFF   mov dword ptr ss:[ebp-0xE4],esp
62269DDF    8BCC            mov ecx,esp
62269DE1    50              push eax
62269DE2    E8 79A4EFFF     call WeChatWi.62164260
62269DE7    FFB6 34030000   push dword ptr ds:[esi+0x334]           ; ��ӵ����� Ⱥ��Ӻ���6 Ⱥ����E ��Ƭ������0x11
62269DED    85FF            test edi,edi
62269DEF    74 06           je short WeChatWi.62269DF7
62269DF1    66:833F 00      cmp word ptr ds:[edi],0x0
62269DF5    75 05           jnz short WeChatWi.62269DFC
62269DF7    BF D838FA62     mov edi,WeChatWi.62FA38D8
62269DFC    83EC 14         sub esp,0x14
62269DFF    8BCC            mov ecx,esp
62269E01    89A5 18FFFFFF   mov dword ptr ss:[ebp-0xE8],esp          ; ���Բ���д
62269E07    6A FF           push -0x1                                ; -1
62269E09    57              push edi                                 ; ��Ϣ����  
62269E0A    E8 11103200     call WeChatWi.6258AE20
62269E0F    FFB6 2C030000   push dword ptr ds:[esi+0x32C]            ; 2
62269E15    83EC 14         sub esp,0x14
62269E18    8BCC            mov ecx,esp
62269E1A    89A5 20FFFFFF   mov dword ptr ss:[ebp-0xE0],esp          ; ���Բ���д
62269E20    53              push ebx                                 ; ΢��ID�Ľṹ�� �������Ա v1�ṹ��
62269E21    E8 3A103200     call WeChatWi.6258AE60
62269E26    C645 FC 06      mov byte ptr ss:[ebp-0x4],0x6
62269E2A    E8 2120EFFF     call WeChatWi.6215BE50
62269E2F    8BC8            mov ecx,eax
62269E31    C645 FC 01      mov byte ptr ss:[ebp-0x4],0x1
62269E35    E8 86B31000     call WeChatWi.623751C0
```

```assembly
83EC 18  C645 FC 03 8D86 ???????? 89A5 1CFFFFFF 8BCC 50 E8 ???????? FFB6 ???????? 85FF 74 ?? 66:833F 00 75 ?? BF ???????? 83EC 14 8BCC 89A5 18FFFFFF 6A FF 57 E8 ???????? FFB6 ???????? 83EC 14 8BCC 89A5 20FFFFFF 53 E8 ???????? C645 ?? 06 E8 ???????? 8BC8 C645 FC 01 E8 ????????
```

### Ⱥ����

```assembly
0FD94079    50              push eax                                 ; ΢��ID
0FD9407A    E8 911E0000     call WeChatWi.0FD95F10                   ; ������װ΢��ID�ṹ���call
-----------------------------------------------------------------------------------------
0FD9412F    6A 00           push 0x0
0FD94131    68 A4D8FA10     push WeChatWi.10FAD8A4
0FD94136    8D4D C0         lea ecx,dword ptr ss:[ebp-0x40]
0FD94139    E8 D2D84200     call WeChatWi.101C1A10                   ; һ��Ҫ���õ�call ����΢�Ż����
-----------------------------------------------------------------------------------------
0FD941EC    83EC 14         sub esp,0x14
0FD941EF    8D8B 80080000   lea ecx,dword ptr ds:[ebx+0x880]
0FD941F5    8BC4            mov eax,esp
0FD941F7    8965 E8         mov dword ptr ss:[ebp-0x18],esp
0FD941FA    50              push eax
0FD941FB    E8 90300100     call WeChatWi.0FDA7290                   ; ����ջ��д��Ⱥ��
-----------------------------------------------------------------------------------------
0FC4422B    C645 FC 03      mov byte ptr ss:[ebp-0x4],0x3
0FC4422F    56              push esi                                 ; ΢��ID�ṹ��
0FC44230    B9 C0DDE510     mov ecx,WeChatWi.10E5DDC0
0FC44235    C645 FC 02      mov byte ptr ss:[ebp-0x4],0x2
0FC44239    E8 920E2100     call WeChatWi.0FE550D0
0FC4423E    E9 70010000     jmp WeChatWi.0FC443B3
```

```assembly
83EC 14 8D8B 80080000 8BC4 8965 E8 50 E8 ???????? C645 FC 03
```

###���˳�΢��

```assembly
615B2097    68 60DF2462     push WeChatWi.6224DF60                   ; ASCII "User Logout"
615B209C    68 38DF2462     push WeChatWi.6224DF38                   ; ASCII "AccountService"
615B20A1    68 48DF2462     push WeChatWi.6224DF48                   ; ASCII "AccountService::logout"
615B20A6    68 56010000     push 0x156
615B20AB    E8 90EB0800     call WeChatWi.61640C40
615B20B0    83C4 6C         add esp,0x6C
615B20B3    E8 78040000     call WeChatWi.615B2530                   ; �˳�΢��
615B20B8    EB 1C           jmp short WeChatWi.615B20D6
615B20BA    68 6CDF2462     push WeChatWi.6224DF6C                   ; ASCII "Kicked by Srv Logout onLogout(0,0,0)"
615B20BF    68 38DF2462     push WeChatWi.6224DF38                   ; ASCII "AccountService"
615B20C4    68 48DF2462     push WeChatWi.6224DF48                   ; ASCII "AccountService::logout"
615B20C9    68 5B010000     push 0x15B
615B20CE    E8 6DEB0800     call WeChatWi.61640C40
615B20D3    83C4 70         add esp,0x70
```

```assembly
68 ???????? 68 ???????? 68 ???????? 68 56010000 E8 ???????? 83C4 6C E8 ???????? EB ?? 68 ???????? 68 ???????? 68 ???????? 68 5B010000 E8 ???????? 83C4 70
```

### ɾ������

```assembly
5CAE24DD    51              push ecx
5CAE24DE    57              push edi  ;΢��ID�Ľṹ��
5CAE24DF    E8 7C211000     call WeChatWi.5CBE4660                   ; ɾ����ϵ��call
5CAE24E4    8D8D 58FFFFFF   lea ecx,dword ptr ss:[ebp-0xA8]
5CAE24EA    E9 E4030000     jmp WeChatWi.5CAE28D3
```

```assembly
51 57 E8 ???????? 8D8D 58FFFFFF E9 ????????
```

### �˳�Ⱥ��

```assembly
0FB72716    84C0            test al,al
0FB72718    0F84 CB000000   je WeChatWi.0FB727E9
0FB7271E    E8 EDD8EDFF     call WeChatWi.0FA50010
-----------------------------------------------------------------------------------------
0FB72723    57              push edi			;ȺID�Ľṹ��
0FB72724    E8 C77B0F00     call WeChatWi.0FC6A2F0 ;�˳�Ⱥ
```

```assembly
84C0 0F84 ???????? E8 ???????? 57 E8 ????????
```

### ��ת����ά�����

```assembly
50A726A8    C745 FC FFFFFFF>mov dword ptr ss:[ebp-0x4],-0x1
50A726AF    E8 2C1DECFF     call WeChatWi.509343E0
50A726B4    E8 77C7FFFF     call WeChatWi.50A6EE30					 ;���callҲҪ����
50A726B9    8BC8            mov ecx,eax                              ; WeChatWi.51AFF610
50A726BB    E8 B0090F00     call WeChatWi.50B63070                   ; ��ת����ά���¼����
50A726C0    8B4D F4         mov ecx,dword ptr ss:[ebp-0xC]
```

```assembly
E8 ???????? E8 ???????? 8BC8 E8 ???????? 8B4D F4
```

### �������ݿ�

```assembly
68C509CB  |> \8D45 E8       lea eax,[local.6]
68C509CE  |.  50            push eax                                 ;  ���ݿ���Կ�ṹ��
68C509CF  |.  56            push esi                                 ;  ���
68C509D0  |.  57            push edi                                 ;  Ҫ���ܵ����ݿ�����
68C509D1  |.  E8 5AFAFFFF   call WeChatWi.68C50430                   ;  �������ݿ��call
68C509D6  |>  8D4D E8       lea ecx,[local.6]
68C509D9  |.  C645 FC 02    mov byte ptr ss:[ebp-0x4],0x2
```

```assembly
8D45E8 50 56 57 E8 ???????? 8D4D E8 C645FC02
```

### �տ�

```assembly
618A6AA7    83EC 30         sub     esp, 0x30
618A6AAA    8945 D0         mov     dword ptr [ebp-0x30], eax
618A6AAD    8BCC            mov     ecx, esp
618A6AAF    8D45 A8         lea     eax, dword ptr [ebp-0x58]
618A6AB2    C745 D4 0000000>mov     dword ptr [ebp-0x2C], 0x0
618A6AB9    50              push    eax
618A6ABA    E8 51000000     call    WeChatWi.618A6B10
618A6ABF    E8 CC000000     call    WeChatWi.618A6B90
618A6AC4    83C4 30         add     esp, 0x30
```

```assembly
50 E8 ???????? E8 ???????? 83C4 30
```

### ��ֹ����

```assembly
53FE254C    83EC 14         sub esp,0x14
53FE254F    8BCC            mov ecx,esp
53FE2551    6A 00           push 0x0
53FE2553    FF70 04         push dword ptr ds:[eax+0x4]
53FE2556    E8 B5F41600     call WeChatWi.54151A10
53FE255B    E8 B052F4FF     call WeChatWi.53F27810                   ; ���ص�call
53FE2560    83C4 14         add esp,0x14
53FE2563    84C0            test al,al
53FE2565    74 72           je short WeChatWi.53FE25D9               ; ��תûʵ�־ͻ᳷��
53FE2567    0F1005 D03DCD54 movups xmm0,dqword ptr ds:[0x54CD3DD0]
53FE256E    83EC 10         sub esp,0x10
53FE2571    8BC4            mov eax,esp
53FE2573    83EC 10         sub esp,0x10
```

```assembly
83EC 14 8BCC 6A00 FF70 04 E8 ???????? E8 ???????? 83C4 14 84C0 74 ?? 0F1005 D03DCD54 83EC 10 8BC4 83EC 10
```

### ͬ���������

```assembly
623BF155    83EC 14         sub esp,0x14
623BF158    54              push esp
623BF159    E8 52740000     call WeChatWi.623C65B0                   ; ѹ��V2
623BF15E    8B8F 48050000   mov ecx,dword ptr ds:[edi+0x548]
623BF164    8D45 DC         lea eax,dword ptr ss:[ebp-0x24]
623BF167    50              push eax
623BF168    E8 8303EDFF     call WeChatWi.6228F4F0                   ; ѹ��V1
623BF16D    8BF0            mov esi,eax
623BF16F    83EC 08         sub esp,0x8
623BF172    C745 FC 0000000>mov dword ptr ss:[ebp-0x4],0x0
623BF179    8B0D 50E04A63   mov ecx,dword ptr ds:[0x634AE050]        ; 113221C
623BF17F    E8 6CF3F4FF     call WeChatWi.6230E4F0                   ; ��ȡeax��ֵ
623BF184    8BD7            mov edx,edi
623BF186    8D8F 14050000   lea ecx,dword ptr ds:[edi+0x514]
623BF18C    F7DA            neg edx
623BF18E    50              push eax                                 ; eax���ϸ�call�ķ���ֵ
623BF18F    1BD2            sbb edx,edx
623BF191    23D1            and edx,ecx
623BF193    8D8F 4C050000   lea ecx,dword ptr ds:[edi+0x54C]
623BF199    52              push edx                                 ; 0x130��С�յĻ�����
623BF19A    56              push esi                                 ; v1�ṹ��
623BF19B    E8 A0CBFEFF     call WeChatWi.623ABD40                   ; ͬ����ѹؼ�call
```

```assembly
83EC 14 54 E8 ???????? 8B8F ???????? 8D45 ?? 50 E8 ???????? 8BF0
```

### ɾ��Ⱥ��Ա

```assembly
707A4AAF    83EC 14         sub esp,0x14
707A4AB2    8D83 54040000   lea eax,dword ptr ds:[ebx+0x454]
707A4AB8    8BCC            mov ecx,esp
707A4ABA    89A5 58FEFFFF   mov dword ptr ss:[ebp-0x1A8],esp         ; �����Բ�д
707A4AC0    50              push eax                                 ; ȺID�ṹ��
707A4AC1    E8 3ACE3600     call WeChatWi.70B11900
707A4AC6    57              push edi                                 ; Ⱥ��Ա΢��ID�ṹ��
707A4AC7    C645 FC 08      mov byte ptr ss:[ebp-0x4],0x8            ; �����Բ�д
707A4ACB    E8 40B5F3FF     call WeChatWi.706E0010
707A4AD0    8BC8            mov ecx,eax
707A4AD2    C645 FC 05      mov byte ptr ss:[ebp-0x4],0x5            ; �����Բ�д
707A4AD6    E8 15081500     call WeChatWi.708F52F0                   ; ���callҲ�������
```

```assembly
 83EC 14 8D83 54040000 8BCC 89A5 58FEFFFF 50 E8 ???????? 57 C645 FC 08 E8 ???????? 8BC8 C645 FC 05 E8 ????????
```


