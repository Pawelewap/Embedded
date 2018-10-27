/* defines and typedefs */
#define GPIO_G_ADDR_MODER   ((volatile int*)  0x40021800)						// base G MODER address
#define GPIO_D_ADDR_MODER   ((volatile int*)  0x40020C00)						// base D MODER address
#define GPIO_G_ODR    		  ((volatile int*)( 0x40021800 + 0x14))		// base G MODER address + offset for ODR
#define GPIO_D_ODR				  ((volatile int*)( 0x40020C00 + 0x14))		// base D MODER address + offset for ODR
#define RCC_AHB1ENR				  ((volatile int*)( 0x40023800 + 0x30)) 	// base RCC address + offset for AHB1ENR register
enum {FALSE = 0, TRUE} bool;

/* function prototype */
void DelayMain(void);
 
/* main function */
int main()
{
	*(RCC_AHB1ENR) |= 0x40 | 0x08; 																							// set clock "on" for G and D ports (0100 0000 bin) | (0000 1000 bin)
	*(GPIO_G_ADDR_MODER) |= (0x01u << 24u) | ((0x01u << 26u) | (0x01u << 28u)); // PIN PG12 | (PIN PG13 | PIN PG14)
	*(GPIO_D_ADDR_MODER) |= (0x01u << 12u); 																		// PIN PD6
	
 while (TRUE) /* infinity loop */
 {
	*(GPIO_D_ODR) |=  (0x01u << 6u);	 // ODR6 ON		(D port)
	*(GPIO_G_ODR) &= ~(0x01u << 12u);  // ODR12 OFF (G port)
  *(GPIO_G_ODR) |=  (0x01u << 13u);  // ODR13 ON  (G port)
	*(GPIO_G_ODR) &= ~(0x01u << 14u);  // ODR14 OFF (G port)
	 
  DelayMain();
	 
  *(GPIO_G_ODR) &= ~(0x01u << 13u); // ODR13 OFF  (G port)
	*(GPIO_G_ODR) |= (0x01u << 14u);  // ODR14 ON   (G port)
	 
  DelayMain();
	
	*(GPIO_G_ODR) &= ~(0x01u << 14u); // ODR14 OFF  (G port)
	*(GPIO_G_ODR) |=  (0x01u << 12u); // ODR12 ON   (G port)
	 
	DelayMain();
 }
}

void DelayMain(void)
{
 volatile int i;
 for (i = 0; i != 0xFFFFF; i++);
}
