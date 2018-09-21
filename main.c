#include "macros.h"
#include <ulk.h>

int main(void) PROGRAM_ENTRY;

struct PIXEL
{
	unsigned int x;
	unsigned int y;
};
extern struct PIXEL pixel;
extern struct PIXEL ulk_proc_touch_spi_enable(void);
extern struct PIXEL ulk_proc_touch_spi_poll(void);
extern void ulk_proc_touch_spi_disable(void);

int main()
{//welcome note

ulk_fpga_clcd_init();
	ulk_fpga_clcd_display_on();
	ulk_fpga_clcd_display_clear();
	ulk_fpga_clcd_cursor_home();
	ulk_proc_delay(ULK_SEC(1));
	ulk_fpga_clcd_display_string("WELCOME TO READERS ANONYMOUS");
	ulk_proc_delay(ULK_SEC(3));
ulk_fpga_clcd_display_off(); //enabling and disabling clcd
ulk_cpanel_printf("1.Mystery and Thriller - press red\n");
ulk_cpanel_printf("2.Fantasy - press yellow\n");
ulk_cpanel_printf("3.Fiction - press blue\n");
ulk_cpanel_printf("4.Self Help - press white\n");
ulk_cpanel_printf("5.Horror - press black\n");
ulk_cpanel_printf("6.Classics - press green\n");

//displaying colours in glcd

int row=0,column=0, *address = 0x80500000;
	for(row=0;row<240;row++)
	{
		for(column=0; column<320; column++)
		{
			if(row<120&&column<100)
			*(address+(row*320)+column)=0xFF0000; //red
			else if(row<120&&column>100&&column<220)
			*(address+(row*320)+column)=0xFFFF00; //yellow
			else if(row>120&&column<100)
			*(address+(row*320)+column)=0x0000FF;   //blue
			else if(row>120&&column>100&&column<220)
			*(address+(row*320)+column)=0xFFFFFF; //white
			else if(row<120&&column>220)
			*(address+(row*320)+column)=0x000000; //black
			else
		    *(address+(row*320)+column)=0x00FF00; //Green

		}
	}


	ulk_proc_touch_spi_enable();

	while(1)
{
	pixel=ulk_proc_touch_spi_poll();

	if (pixel.x!=0 && pixel.y!=0)
	{

		break;
	}
}
ulk_proc_touch_spi_disable();


if (pixel.x<120&&pixel.y<100) //Red
 {
	ulk_proc_led_config(0);
  	ulk_proc_led_drive(0,1);
ulk_fpga_7seg_led_enable();
		ulk_fpga_7seg_led_write(1);
	   	   ulk_proc_delay(ULK_SEC(5));
	   	   ulk_fpga_7seg_led_disable();

ulk_fpga_clcd_init();
	ulk_fpga_clcd_display_on();
	ulk_fpga_clcd_display_clear();
	ulk_fpga_clcd_cursor_home();
	ulk_fpga_clcd_display_string("MYSTERY & THRILLER");
	ulk_proc_delay(ULK_SEC(3));

ulk_fpga_clcd_display_off();
ulk_cpanel_printf("1.Jeffrey Archer - press black\n");
ulk_cpanel_printf("2.Dan Brown - press yellow\n");
ulk_cpanel_printf("3.Agatha Christie - press blue\n");
ulk_cpanel_printf("4.James Patterson - press white\n");


int row=0,column=0, *address = 0x80500000; //To display colours
	for(row=0;row<240;row++)
	{
		for(column=0; column<320; column++)
		{
			if(row<120&&column<160)
			*(address+(row*320)+column)=0x000000;
			else if(row<120&&column>160)
			*(address+(row*320)+column)=0xFFFF00;
			else if(row>120&&column<160)
			*(address+(row*320)+column)=0x0000FF;
			else
			*(address+(row*320)+column)=0xFFFFFF;
		}
	}

	ulk_proc_touch_spi_enable();

	while(1)
{
	pixel=ulk_proc_touch_spi_poll();

	if (pixel.x!=0 && pixel.y!=0)
	{

		break;
	}
}
ulk_proc_touch_spi_disable();

	if(pixel.x<120&&pixel.y<160)
	{
	ulk_fpga_clcd_init();
	ulk_fpga_clcd_display_on();
	ulk_fpga_clcd_display_clear();
	ulk_fpga_clcd_cursor_home();
        
	ulk_fpga_clcd_display_string("TELL TALE");
        ulk_proc_delay(ULK_SEC(3));
	ulk_fpga_clcd_display_string("ONLY TIME WILL TELL");
	ulk_proc_delay(ULK_SEC(3));
	ulk_fpga_clcd_display_off();
	}

	else if(pixel.x<120&&pixel.y>160)
	{
		ulk_fpga_clcd_init();
		ulk_fpga_clcd_display_on();
		ulk_fpga_clcd_display_clear();
		ulk_fpga_clcd_cursor_home();
			
		ulk_fpga_clcd_display_string("THE DA VINCI CODE");
		ulk_proc_delay(ULK_SEC(3));
		ulk_fpga_clcd_display_string("ORIGIN");
		ulk_proc_delay(ULK_SEC(3));
		ulk_fpga_clcd_display_off();
	}

	else if(pixel.x>120&&pixel.y<160)
	{
	ulk_fpga_clcd_init();
		ulk_fpga_clcd_display_on();
		ulk_fpga_clcd_display_clear();
		ulk_fpga_clcd_cursor_home();
		
		ulk_fpga_clcd_display_string("ENDLESS NIGHT");
		ulk_proc_delay(ULK_SEC(3));
		ulk_fpga_clcd_display_string("FIVE LITTLE PIGS");
		ulk_proc_delay(ULK_SEC(3));
		ulk_fpga_clcd_display_off();
	}
	else
 	{
		ulk_fpga_clcd_init();
		ulk_fpga_clcd_display_on();
		ulk_fpga_clcd_display_clear();
		ulk_fpga_clcd_cursor_home();
				
		ulk_fpga_clcd_display_string("CROSS");
 		ulk_proc_delay(ULK_SEC(3));		
		ulk_fpga_clcd_display_string("PRIVATE");
		ulk_proc_delay(ULK_SEC(3));
		ulk_fpga_clcd_display_off();
	}

 	}

	ulk_proc_touch_spi_enable();
while(1)
{
	pixel=ulk_proc_touch_spi_poll();
	if (pixel.x!=0 && pixel.y!=0)
	{

		break;
	}
}
ulk_proc_touch_spi_disable();


if (pixel.x>120&&pixel.y<100) //Blue
{
ulk_fpga_7seg_led_enable();
		ulk_fpga_7seg_led_write(4);
	   	   ulk_proc_delay(ULK_SEC(5));
	   	   ulk_fpga_7seg_led_disable();

	   	ulk_fpga_clcd_init();
	   		ulk_fpga_clcd_display_on();
	   		ulk_fpga_clcd_display_clear();
	   		ulk_fpga_clcd_cursor_home();
	   		ulk_fpga_clcd_display_string("FICTION");
			ulk_proc_delay(ULK_SEC(3));

	   	ulk_fpga_clcd_display_off();
	   	ulk_cpanel_printf("1.J.K.Rowling - press black\n");
	   	ulk_cpanel_printf("2.Paulo Coelho - press yellow\n");
	   	ulk_cpanel_printf("3.Roald Dahl - press blue\n");
	   	ulk_cpanel_printf("4.Stephenie Meyer - press white\n");


	   	int row=0,column=0, *address = 0x80500000;
	   		for(row=0;row<240;row++)
	   		{
	   			for(column=0; column<320; column++)
	   			{
	   				if(row<120&&column<160)
	   				*(address+(row*320)+column)=0x000000;
	   				else if(row<120&&column>160)
	   				*(address+(row*320)+column)=0xFFFF00;
	   				else if(row>120&&column<160)
	   				*(address+(row*320)+column)=0x0000FF;
	   				else
	   				*(address+(row*320)+column)=0xFFFFFF;
	   			}
	   		}
	   		ulk_proc_touch_spi_enable();

	   			while(1)
	   		{
	   			pixel=ulk_proc_touch_spi_poll();

	   			if (pixel.x!=0 && pixel.y!=0)
	   			{

	   				break;
	   			}
	   		}
	   		ulk_proc_touch_spi_disable();

	   		if(pixel.x<120&&pixel.y<160)
	   		{
	   			ulk_fpga_clcd_init();
	   			ulk_fpga_clcd_display_on();
	   			ulk_fpga_clcd_display_clear();
	   			ulk_fpga_clcd_cursor_home();
				
	   			ulk_fpga_clcd_display_string("HARRY POTTER SERIES");
				ulk_proc_delay(ULK_SEC(3));
	   			ulk_fpga_clcd_display_off();
	   		}

	   		else if(pixel.x<120&&pixel.y>160)
	   		{
	   			ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
					
	   				ulk_fpga_clcd_display_string("THE ALCHEMIST");
	   				ulk_proc_delay(ULK_SEC(3));
					ulk_fpga_clcd_display_string("ELEVEN MIUNUTES");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}

	   		else if(pixel.x>120&&pixel.y<160)
	   			{
	   			  	ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				
					ulk_fpga_clcd_display_string("MATILDA");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_string("THE BFG");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}
	   		else
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				
					ulk_fpga_clcd_display_string("TWILIGHT SERIES");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}

}

else if(pixel.x<120&&pixel.y>100&&pixel.y<220) //Yellow
{
ulk_fpga_7seg_led_enable();
		ulk_fpga_7seg_led_write(2);
	   	   ulk_proc_delay(ULK_SEC(5));
	   	   ulk_fpga_7seg_led_disable();

	   	ulk_fpga_clcd_init();
	   		ulk_fpga_clcd_display_on();
	   		ulk_fpga_clcd_display_clear();
	   		ulk_fpga_clcd_cursor_home();
	   		ulk_fpga_clcd_display_string("FANTASY");
 			ulk_proc_delay(ULK_SEC(3));

	   	ulk_fpga_clcd_display_off();
	   	ulk_cpanel_printf("1.Sidney Sheldon - press black\n");
	   	ulk_cpanel_printf("2.Rick Riordan - press yellow\n");
	   	ulk_cpanel_printf("3.Suzanne Collins - press blue\n");
	   	ulk_cpanel_printf("4.George R.R.Martin - press white\n");


	   	int row=0,column=0, *address = 0x80500000;
	   		for(row=0;row<240;row++)
	   		{
	   			for(column=0; column<320; column++)
	   			{
	   				if(row<120&&column<160)
	   				*(address+(row*320)+column)=0x000000;
	   				else if(row<120&&column>160)
	   				*(address+(row*320)+column)=0xFFFF00;
	   				else if(row>120&&column<160)
	   				*(address+(row*320)+column)=0x0000FF;
	   				else
	   				*(address+(row*320)+column)=0xFFFFFF;
	   			}

}

	   		ulk_proc_touch_spi_enable();

	   			while(1)
	   		{
	   			pixel=ulk_proc_touch_spi_poll();

	   			if (pixel.x!=0 && pixel.y!=0)
	   			{

	   				break;
	   			}
	   		}
	   		ulk_proc_touch_spi_disable();

	   		if(pixel.x<120&&pixel.y<160)
	   		{
	   			ulk_fpga_clcd_init();
	   			ulk_fpga_clcd_display_on();
	   			ulk_fpga_clcd_display_clear();
	   			ulk_fpga_clcd_cursor_home();
				
	   			ulk_fpga_clcd_display_string("IF TOMORROW COMES");
				ulk_proc_delay(ULK_SEC(3));
	   			ulk_fpga_clcd_display_string("BLOODLINE");
				ulk_proc_delay(ULK_SEC(3));
	   			ulk_fpga_clcd_display_off();
	   		}

	   		else if(pixel.x<120&&pixel.y>160)
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
					
	   				ulk_fpga_clcd_display_string("PERCY JACKSON SERIES");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}

	   		else if(pixel.x>120&&pixel.y<160)
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				ulk_fpga_clcd_display_string("HUNGER GAMES");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}
	   		else
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				ulk_fpga_clcd_display_string("GOT SERIES");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}

		}

	else if(pixel.x<120&&pixel.y>220) //Black
		{
			ulk_fpga_7seg_led_enable();
			ulk_fpga_7seg_led_write(3);
	   	  	 ulk_proc_delay(ULK_SEC(5));

	   	  	 ulk_fpga_7seg_led_disable();

	   		ulk_fpga_clcd_init();
	   		ulk_fpga_clcd_display_on();
	   		ulk_fpga_clcd_display_clear();
	   		ulk_fpga_clcd_cursor_home();
	   		ulk_fpga_clcd_display_string("HORROR");
			ulk_proc_delay(ULK_SEC(3));

	   	ulk_fpga_clcd_display_off();
	   	ulk_cpanel_printf("1.Stephen King - press black\n");
	   	ulk_cpanel_printf("2.Dean Koontz - press yellow\n");
	   	ulk_cpanel_printf("3.Clive Barker - press blue\n");
	   	ulk_cpanel_printf("4.Peter Straub - press white\n");


	   	int row=0,column=0, *address = 0x80500000;
	   		for(row=0;row<240;row++)
	   		{
	   			for(column=0; column<320; column++)
	   			{
	   				if(row<120&&column<160)
	   				*(address+(row*320)+column)=0x000000;
	   				else if(row<120&&column>160)
	   				*(address+(row*320)+column)=0xFFFF00;
	   				else if(row>120&&column<160)
	   				*(address+(row*320)+column)=0x0000FF;
	   				else
	   				*(address+(row*320)+column)=0xFFFFFF;
	   			}

}
	   		ulk_proc_touch_spi_enable();

	   			while(1)
	   		{
	   			pixel=ulk_proc_touch_spi_poll();

	   			if (pixel.x!=0 && pixel.y!=0)
	   			{

	   				break;
	   			}
	   		}
	   		ulk_proc_touch_spi_disable();

	   		if(pixel.x<120&&pixel.y<160)
	   		{
	   			ulk_fpga_clcd_init();
	   			ulk_fpga_clcd_display_on();
	   			ulk_fpga_clcd_display_clear();
	   			ulk_fpga_clcd_cursor_home();
	   			ulk_fpga_clcd_display_string("IT");
				ulk_proc_delay(ULK_SEC(3));
	   			ulk_fpga_clcd_display_string("THE OUTSIDER");
				ulk_proc_delay(ULK_SEC(3));
	   			ulk_fpga_clcd_display_off();
	   		}

	   		else if(pixel.x<120&&pixel.y>160)
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				ulk_fpga_clcd_display_string("WATCHERS");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_string("ODD THOMAS");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}

	   		else if(pixel.x>120&&pixel.y<160)
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				ulk_fpga_clcd_display_string("IMAGICA");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_string("ABARAT");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}
	   		else
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				ulk_fpga_clcd_display_string("GHOST STORY");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_string("A DARK MATTER");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}

}

else if(pixel.x>120&&pixel.y<220&&pixel.y>100)
{
			ulk_fpga_7seg_led_enable();
			ulk_fpga_7seg_led_write(5);
	   	 	ulk_proc_delay(ULK_SEC(5));
	   		ulk_fpga_7seg_led_disable();
	   		ulk_fpga_clcd_init();
	   		ulk_fpga_clcd_display_on();
	   		ulk_fpga_clcd_display_clear();
	   		ulk_fpga_clcd_cursor_home();
	   		ulk_fpga_clcd_display_string("SELF-HELP");
			ulk_proc_delay(ULK_SEC(3));

	   	ulk_fpga_clcd_display_off();
	   	ulk_cpanel_printf("1.Dale Carnegie - press black\n");
	   	ulk_cpanel_printf("2.Napoleon Hill - press yellow\n");
	   	ulk_cpanel_printf("3.Lilly Singh - press blue\n");
	   	ulk_cpanel_printf("4.Stephen R.Covey - press white\n");


	   	int row=0,column=0, *address = 0x80500000;
	   		for(row=0;row<240;row++)
	   		{
	   			for(column=0; column<320; column++)
	   			{
	   				if(row<120&&column<160)
	   				*(address+(row*320)+column)=0x000000;
	   				else if(row<120&&column>160)
	   				*(address+(row*320)+column)=0xFFFF00;
	   				else if(row>120&&column<160)
	   				*(address+(row*320)+column)=0x0000FF;
	   				else
	   				*(address+(row*320)+column)=0xFFFFFF;
	   			}

}
	   		ulk_proc_touch_spi_enable();

	   			while(1)
	   		{
	   			pixel=ulk_proc_touch_spi_poll();

	   			if (pixel.x!=0 && pixel.y!=0)
	   			{

	   				break;
	   			}
	   		}
	   		ulk_proc_touch_spi_disable();

	   		if(pixel.x<120&&pixel.y<160)
	   			{
	   			ulk_fpga_clcd_init();
	   			ulk_fpga_clcd_display_on();
	   			ulk_fpga_clcd_display_clear();
	   			ulk_fpga_clcd_cursor_home();
	   			ulk_fpga_clcd_display_string("THE LEADER IN YOU");
				ulk_proc_delay(ULK_SEC(3));
	   			ulk_fpga_clcd_display_string("LINCOLN THE UNKNOWN");
				ulk_proc_delay(ULK_SEC(3));
	   			ulk_fpga_clcd_display_off();
	   			}

	   		else if(pixel.x<120&&pixel.y>160)
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				ulk_fpga_clcd_display_string("THINK AND GROW RICH");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}

	   		else if(pixel.x>120&&pixel.y<160)
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				ulk_fpga_clcd_display_string("THE BAWSE");
					ulk_proc_delay(ULK_SEC(3));

	   				ulk_fpga_clcd_display_off();
	   			}
	   		else
	   			{
	   				ulk_fpga_clcd_init();
	   				ulk_fpga_clcd_display_on();
	   				ulk_fpga_clcd_display_clear();
	   				ulk_fpga_clcd_cursor_home();
	   				ulk_fpga_clcd_display_string("FIRST THINGS FIRST");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_string("THE 8th HABIT");
					ulk_proc_delay(ULK_SEC(3));
	   				ulk_fpga_clcd_display_off();
	   			}

		}

		else
		{
				ulk_fpga_7seg_led_enable();
			        ulk_fpga_7seg_led_write(6);
		   	  	ulk_proc_delay(ULK_SEC(5));
		   	  	ulk_fpga_7seg_led_disable();

		   		ulk_fpga_clcd_init();
		   		ulk_fpga_clcd_display_on();
		   		ulk_fpga_clcd_display_clear();
		   		ulk_fpga_clcd_cursor_home();
		   		ulk_fpga_clcd_display_string("CLASSICS");
				ulk_proc_delay(ULK_SEC(3));

		   	ulk_fpga_clcd_display_off();
		   	ulk_cpanel_printf("1.Jane Austin - press black\n");
		   	ulk_cpanel_printf("2.Charles Dickens - press yellow\n");
		   	ulk_cpanel_printf("3.Leo Tolstoy - press blue\n");
		   	ulk_cpanel_printf("4.Mark Twain - press white\n");


		   	int row=0,column=0, *address = 0x80500000;
		   		for(row=0;row<240;row++)
		   		{
		   			for(column=0; column<320; column++)
		   			{
		   				if(row<120&&column<160)
		   				*(address+(row*320)+column)=0x000000;
		   				else if(row<120&&column>160)
		   				*(address+(row*320)+column)=0xFFFF00;
		   				else if(row>120&&column<160)
		   				*(address+(row*320)+column)=0x0000FF;
		   				else
		   				*(address+(row*320)+column)=0xFFFFFF;
		   			}
		   		}
		   			ulk_proc_touch_spi_enable();

		   				while(1)
		   			{
		   				pixel=ulk_proc_touch_spi_poll();

		   				if (pixel.x!=0 && pixel.y!=0)
		   				{

		   					break;
		   				}
		   			}
		   			ulk_proc_touch_spi_disable();

		   			if(pixel.x<120&&pixel.y<160)
		   				{
		   				ulk_fpga_clcd_init();
		   				ulk_fpga_clcd_display_on();
		   				ulk_fpga_clcd_display_clear();
		   				ulk_fpga_clcd_cursor_home();
		   				ulk_fpga_clcd_display_string("PRIDE AND PREJUDICE");
						ulk_proc_delay(ULK_SEC(3));
		   				ulk_fpga_clcd_display_string("EMMA");
						ulk_proc_delay(ULK_SEC(3));
		   				ulk_fpga_clcd_display_off();
		   				}

		   			else if(pixel.x<120&&pixel.y>160)
		   				{
		   					ulk_fpga_clcd_init();
		   					ulk_fpga_clcd_display_on();
		   					ulk_fpga_clcd_display_clear();
		   					ulk_fpga_clcd_cursor_home();
		   					ulk_fpga_clcd_display_string("OLIVER TWIST");
							ulk_proc_delay(ULK_SEC(3));
		   					ulk_fpga_clcd_display_string("DAVID COPPERFIELD");
							ulk_proc_delay(ULK_SEC(3));
		   					ulk_fpga_clcd_display_off();
		   				}

		   			else if(pixel.x>120&&pixel.y<160)
		   				{
		   					ulk_fpga_clcd_init();
		   					ulk_fpga_clcd_display_on();
		   					ulk_fpga_clcd_display_clear();
		   					ulk_fpga_clcd_cursor_home();
		   					ulk_fpga_clcd_display_string("WAR AND PEACE");
							ulk_proc_delay(ULK_SEC(3));
		   					ulk_fpga_clcd_display_string("RESURRECTION");
							ulk_proc_delay(ULK_SEC(3));
		   					ulk_fpga_clcd_display_off();
		   				}
		   			else
		   				{
		   					ulk_fpga_clcd_init();
		   					ulk_fpga_clcd_display_on();
		   					ulk_fpga_clcd_display_clear();
		   					ulk_fpga_clcd_cursor_home();
		   					ulk_fpga_clcd_display_string("ROUGHING IT");
							ulk_proc_delay(ULK_SEC(3));
		   					ulk_fpga_clcd_display_string("A TRAMP ABROAD");
							ulk_proc_delay(ULK_SEC(3));
		   					ulk_fpga_clcd_display_off();
		   				}

		}


		return 0;
		}
