

/******************************************************************************* 
 * Author          :Honker.y 
 * Email           :Honker.ying@gmail.com 
 * Last modified   :2011-04-21 22:34 
 * Filename        :open_file.c 
 * version         :1.0 
 * Description     :GTK实现打开文件操作 
 *Revision         : 
 * Compiler        :gcc 
 * Install         : 
 * Use             : 
 *******************************************************************************/  
#include <stdlib.h>  
#include <gtk/gtk.h>  
  
/** 
 * @brief   创建一个新的横向盒，它包含一个图像和一个标签，并返回这个盒 
 * 
 * @param   xpm_filename 
 * @param   label_text 
 * 
 * @return  box 
 */  
GtkWidget *  
xpm_label_box (gchar * xpm_filename, gchar * label_text)  
{  
  GtkWidget *box;  
  GtkWidget *label;  
  GtkWidget *image;  
  /* 为图像和标签创建盒 */  
  box = gtk_hbox_new (FALSE, 0);  
  gtk_container_set_border_width (GTK_CONTAINER (box), 2);  
  /* 创建一个图像 */  
  image = gtk_image_new_from_file (xpm_filename);  
  /* 为按钮创建一个标签 */  
  label = gtk_label_new (label_text);  
  /* 把图像和标签组装到盒子里 */  
  gtk_box_pack_start (GTK_BOX (box), image, FALSE, FALSE, 3);  
  gtk_box_pack_start (GTK_BOX (box), label, FALSE, FALSE, 3);  
  gtk_widget_show (image);  
  gtk_widget_show (label);  
  return box;  
}  
  
/** 
 * @brief   回调函数，打开文件选项 
 * 
 * @param   widget 
 * @param   data 
 */  
void  
button_openfile (GtkWidget * widget, gpointer * data)  
{  
    GtkWidget *FileSelection;  
    FileSelection = gtk_file_selection_new ("选择文件");    /*创建文件选择构件 */  
    gtk_file_selection_set_filename (GTK_FILE_SELECTION (FileSelection),  
                   "*.jpg *.png *.bmp");  
    gtk_widget_show (FileSelection);  
}  
/** 
 * @brief   主函数 
 * 
 * @param   argc 
 * @param   argv[]] 
 * 
 * @return 
 */  
int  
main (int argc, char *argv[])  
{  
  /* GtkWidget 是构件的存储类型 */  
  GtkWidget *window;  
  GtkWidget *button;  
  GtkWidget *box;  
  gtk_init (&argc, &argv);  
  /* 创建一个新窗口 */  
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);  
  gtk_window_set_title (GTK_WINDOW (window), "DreamPhoto");  
  /* 对所有的窗口做这一步 */  
  g_signal_connect (G_OBJECT (window), "destroy",  
            G_CALLBACK (gtk_main_quit), NULL);  
  g_signal_connect (G_OBJECT (window), "delete_event",  
            G_CALLBACK (gtk_main_quit), NULL);  
  /* 设置窗口边框的宽度 */  
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);  
  /* 创建一个新的按钮 */  
  button = gtk_button_new ();  
  /* 连接按钮的 "clicked" 信号到我们的回调 */  
  g_signal_connect (G_OBJECT (button), "clicked",  
            G_CALLBACK (button_openfile), (gpointer) "打开");  
  /* 调用我们的创建盒的函数 */  
  box = xpm_label_box ("open.png", "打开");  
  /* 组装和显示所有的构件 */  
  gtk_widget_show (box);  
  gtk_container_add (GTK_CONTAINER (button), box);  
  gtk_widget_show (button);  
  gtk_container_add (GTK_CONTAINER (window), button);  
  gtk_widget_show (window);  
  /* 停在这里，等待事件发生。 */  
  gtk_main ();  
  return 0;  
}  
