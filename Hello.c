#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <math.h>

typedef struct Coordinates {
    gchar name[3];
    double x;
    double y;
}Coordinates;

double a, b, c, d, e;
gchar pos1[3], pos2[3];

void activate();

int main(int argc, char **argv)
{
    GtkApplication  *app;
    int             status;
    app     =   gtk_application_new ("jp.vivacocoa.button",     0   );
    g_signal_connect                (app,       "activate",
                                     G_CALLBACK( activate),     NULL);
    status  =   g_application_run   (G_APPLICATION(app), argc,  argv);
    g_object_unref                  (app);
    return      status;
}

void updateAngle(GtkWidget *widget, GtkRange *angle)
{
    gtk_range_set_value(angle, (int) e);
}

void update_status1(GtkRange *range, gpointer label)
{
    gdouble val = gtk_range_get_value(range);
    if ((int)e == (int)val){
        char testing[] = "Launching from ";
        strcat(testing,pos2);
        strcat(testing," to ");
        strcat(testing,pos1);
        gtk_label_set_text  (label, testing);
    }else{
        char testing[] = "Launching at custom angle ";
        gtk_label_set_text  (label, testing);
    }
}

void value_changed(GtkRange *range, gpointer label)
{
    gdouble val     =   gtk_range_get_value(range);
    gchar   *str    =   g_strdup_printf("%.f°", val  );
    gtk_label_set_text  (label, str);
    g_free(str);
}

void value_changed2(GtkRange *range, gpointer label)
{
    gdouble val     =  gtk_range_get_value(range);
    val = 90 - val;
    gchar   *str    =   g_strdup_printf("%.f°", val);
    gtk_label_set_text  (label, str);
    g_free(str);
}

void coordinate_fetch(GtkWidget *widget, struct Coordinates *w)
{
    a = w->x;
    b = w->y;
    strcpy(pos1, w->name);
}

void coordinate_fetch2(GtkWidget *widget, struct Coordinates *w)
{
    c = w->x;
    e = (a-c)/(b-1);
    e = (atan (e)*180)/3.1415926;
    strcpy(pos2, w->name);
    //g_print ("Angle:%d\n", (int)e);
}

void activate(GtkApplication *app, gpointer data)
{
    struct Coordinates *circle[15];
    for (int i=0;i<16;i++){
       circle[i] = (Coordinates *) malloc(sizeof(struct Coordinates));
    }

    /*Storing the coordinates of all platforms and circles*/
    circle[1]->x = 1.5, circle[1]->y = 2, circle[2]->x = 4, circle[2]->y = 2, circle[3]->x = 6.5, circle[3]->y = 2, circle[4]->x = 2.5, circle[4]->y = 4, circle[5]->x = 5.5, circle[5]->y = 4;
    circle[6]->x = 4, circle[6]->y = 5, circle[7]->x = 1.5, circle[7]->y = 7, circle[8]->x = 6.5, circle[8]->y = 7, circle[9]->x = 4, circle[9]->y = 8.5;
    circle[10]->x = 0.4, circle[10]->y = 1, circle[11]->x = 2, circle[11]->y = 1, circle[12]->x = 4, circle[12]->y = 1, circle[13]->x = 6, circle[13]->y = 1, circle[14]->x = 7.6,  circle[14]->y = 1;
    strcpy(circle[1]->name, "A1");
    strcpy(circle[2]->name, "A2");
    strcpy(circle[3]->name, "A3");
    strcpy(circle[4]->name, "B1");
    strcpy(circle[5]->name, "B2");
    strcpy(circle[6]->name, "C1");
    strcpy(circle[7]->name, "D1");
    strcpy(circle[8]->name, "D2");
    strcpy(circle[9]->name, "C2");
    strcpy(circle[10]->name, "E1");
    strcpy(circle[11]->name, "E2");
    strcpy(circle[12]->name, "E3");
    strcpy(circle[13]->name, "E4");
    strcpy(circle[14]->name, "E5");

    /*Setting buttons for the map*/
    GtkWidget   *fcircle1, *fcircle2, *fcircle3, *bcircle1, *bcircle2;
    GtkWidget   *ftube, *lrunway, *rrunway, *btube;
    GtkWidget   *platform1, *platform2, *platform3, *platform4, *platform5;
    GtkWidget   *space1, *space2, *space3, *space4, *space5, *space6;

    fcircle1 = gtk_button_new_with_label ("A1");
    fcircle2 = gtk_button_new_with_label ("A2");
    fcircle3 = gtk_button_new_with_label ("A3");
    bcircle1 = gtk_button_new_with_label ("B1");
    bcircle2 = gtk_button_new_with_label ("B2");
    ftube = gtk_button_new_with_label ("C1");
    lrunway = gtk_button_new_with_label ("D1");
    rrunway = gtk_button_new_with_label ("D2");
    btube = gtk_button_new_with_label ("C2");
    platform1 = gtk_button_new_with_label ("E1");
    platform2 = gtk_button_new_with_label ("E2");
    platform3 = gtk_button_new_with_label ("E3");
    platform4 = gtk_button_new_with_label ("E4");
    platform5 = gtk_button_new_with_label ("E5");

    space1 = gtk_label_new (NULL);
    space2 = gtk_label_new (NULL);
    space3 = gtk_label_new (NULL);
    space4 = gtk_label_new (NULL);
    space5 = gtk_label_new (NULL);
    space6 = gtk_label_new (NULL);

    //Settings the other widgets
    GtkWidget   *window, *thebestgrid, *grid, *grid2;
    GtkWidget   *status, *hframe, *tdframe, *angle, *angle2, *angleframe, *angleframe2;
    GtkWidget   *anglescale, *anglescale2, *shoot, *statusframe, *closewindow;

    hframe = gtk_frame_new (NULL);
    tdframe = gtk_frame_new (NULL);
    shoot = gtk_button_new ();
    closewindow = gtk_button_new_with_label ("X");

    status = gtk_label_new ("System Ready");
    statusframe = gtk_frame_new (NULL);
    gtk_container_add              (GTK_CONTAINER(statusframe), status);

    angle = gtk_label_new ("0°");
    angleframe = gtk_frame_new (NULL);
    gtk_container_add              (GTK_CONTAINER(angleframe), angle);
    gtk_label_set_width_chars (GTK_LABEL (angle),4);

    angle2 = gtk_label_new ("0°");
    angleframe2 = gtk_frame_new (NULL);
    gtk_container_add              (GTK_CONTAINER(angleframe2), angle2);

    anglescale   =  gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, -90, 90, 1);
    gtk_scale_set_draw_value        (GTK_SCALE(anglescale), FALSE);
    gtk_range_set_value (GTK_RANGE (anglescale), 0);
    gtk_scale_add_mark (GTK_SCALE(anglescale),0,GTK_POS_TOP, NULL);
    gtk_scale_set_has_origin (GTK_SCALE(anglescale),FALSE);


    anglescale2   =  gtk_scale_new_with_range (GTK_ORIENTATION_VERTICAL, 0, 90, 1);
    gtk_scale_set_draw_value        (GTK_SCALE(anglescale2), FALSE);
    gtk_range_set_value (GTK_RANGE (anglescale2), 90);
    gtk_scale_add_mark (GTK_SCALE(anglescale2),45,GTK_POS_RIGHT, NULL);
    gtk_scale_set_has_origin (GTK_SCALE(anglescale2),FALSE);


    /*  Window and auto determining the size          */
    gint wwidth, wheight;
    window  = gtk_application_window_new      (app);
    gtk_window_set_title            (GTK_WINDOW(window),    "Grid"  );
    gtk_window_set_position         (GTK_WINDOW(window),    1       );
    gtk_container_set_border_width  (GTK_CONTAINER(window), 15      );
    gtk_window_fullscreen           (GTK_WINDOW (window));
    gtk_widget_show_all             (window);
    gtk_window_get_size             (GTK_WINDOW (window), &wwidth, &wheight);

    //Setting the size of widgets
    gtk_widget_set_size_request     (statusframe,   0.492*wwidth,    0.06*wheight  );
    gtk_widget_set_size_request     (hframe,   0.25*wwidth,    0.44*wheight  );
    gtk_widget_set_size_request     (tdframe,   0.25*wwidth,    0.44*wheight  );
    gtk_widget_set_size_request     (space1,   0.492*wwidth,    0.02*wheight );
    gtk_widget_set_size_request     (space2,   0.492*wwidth,    0.03*wheight );
    gtk_widget_set_size_request     (space3,   0.492*wwidth,    0.03*wheight );
    gtk_widget_set_size_request     (space4,   0.492*wwidth,    0.03*wheight );
    gtk_widget_set_size_request     (space5,   0.492*wwidth,    0.03*wheight );
    gtk_widget_set_size_request     (space6,   0.492*wwidth,    0.115*wheight );
    gtk_widget_set_size_request     (fcircle1,   0.056*wwidth,    0.089*wheight );
    gtk_widget_set_size_request     (fcircle2,   0.056*wwidth,    0.089*wheight );
    gtk_widget_set_size_request     (fcircle3,   0.056*wwidth,    0.089*wheight );
    gtk_widget_set_size_request     (bcircle1,   0.056*wwidth,    0.089*wheight );
    gtk_widget_set_size_request     (bcircle2,   0.056*wwidth,    0.089*wheight );
    gtk_widget_set_size_request     (ftube,   0.04*wwidth,    0.044*wheight );
    gtk_widget_set_size_request     (btube,   0.021*wwidth,    0.089*wheight );
    gtk_widget_set_size_request     (lrunway,   0.021*wwidth,    0.222*wheight );
    gtk_widget_set_size_request     (rrunway,   0.021*wwidth,    0.222*wheight  );
    gtk_widget_set_size_request     (platform1,   0.033*wwidth,    0.067*wheight  );
    gtk_widget_set_size_request     (platform2,   0.1*wwidth,    0.067*wheight  );
    gtk_widget_set_size_request     (platform3,   0.05*wwidth,    0.067*wheight  );
    gtk_widget_set_size_request     (platform4,   0.1*wwidth,    0.067*wheight  );
    gtk_widget_set_size_request     (platform5,   0.033*wwidth,    0.067*wheight  );
    gtk_widget_set_size_request     (shoot,   0.033*wwidth,    0.067*wheight  );

    /*  Grids            */
    thebestgrid = gtk_grid_new();
    gtk_grid_set_column_spacing     (GTK_GRID(thebestgrid),    2  );
    gtk_grid_set_row_spacing        (GTK_GRID(thebestgrid),    1   );
    gtk_container_add               (GTK_CONTAINER(window), thebestgrid);

    grid    =   gtk_grid_new        ();
    gtk_grid_set_column_spacing     (GTK_GRID(grid),    16   );
    gtk_grid_set_row_spacing        (GTK_GRID(grid),    21   );

    grid2    =   gtk_grid_new        ();
    gtk_grid_set_column_spacing     (GTK_GRID(grid2),    24  );
    gtk_grid_set_row_spacing        (GTK_GRID(grid2),    16  );

    /* Making the map */
    /*gtk_grid_attach (~~~, NAME, column, row, width, height)*/
    gtk_grid_attach             (GTK_GRID(thebestgrid), grid , 0, 0, 1, 1 );
    gtk_grid_attach             (GTK_GRID(grid), space1, 0, 0, 15, 1 );
    gtk_grid_attach             (GTK_GRID(grid), btube, 7, 1, 1, 2 );
    gtk_grid_attach             (GTK_GRID(grid), space2, 0, 3, 15, 1 );
    gtk_grid_attach             (GTK_GRID(grid), lrunway , 2, 4, 1, 3 );
    gtk_grid_attach             (GTK_GRID(grid), rrunway , 12, 4, 1, 3 );
    gtk_grid_attach             (GTK_GRID(grid), space3, 0, 7, 15, 2 );
    gtk_grid_attach             (GTK_GRID(grid), ftube, 6, 9, 3, 1 );
    gtk_grid_attach             (GTK_GRID(grid), space4, 0, 10, 15, 1 );
    gtk_grid_attach             (GTK_GRID(grid), bcircle1, 4, 11, 1, 1 );
    gtk_grid_attach             (GTK_GRID(grid), bcircle2, 10, 11, 1, 1 );
    gtk_grid_attach             (GTK_GRID(grid), space5, 0, 12, 15, 3 );
    gtk_grid_attach             (GTK_GRID(grid), fcircle1, 2, 15, 1, 1 );
    gtk_grid_attach             (GTK_GRID(grid), fcircle2, 6, 15, 3, 1 );
    gtk_grid_attach             (GTK_GRID(grid), fcircle3, 12, 15, 1, 1 );
    gtk_grid_attach             (GTK_GRID(grid), space6, 0, 16, 15, 3 );
    gtk_grid_attach             (GTK_GRID(grid), platform1, 0, 19, 2, 2 );
    gtk_grid_attach             (GTK_GRID(grid), platform2, 2, 19, 4, 2 );
    gtk_grid_attach             (GTK_GRID(grid), platform3, 6, 19, 3, 2 );
    gtk_grid_attach             (GTK_GRID(grid), platform4, 9, 19, 4, 2 );
    gtk_grid_attach             (GTK_GRID(grid), platform5, 13, 19, 2, 2 );
    gtk_grid_attach             (GTK_GRID(thebestgrid), grid2 , 1, 0, 1, 1 );

    /*When pressing any button*/
    g_signal_connect             (fcircle1, "clicked", G_CALLBACK(coordinate_fetch), circle[1]);
    g_signal_connect             (fcircle2, "clicked", G_CALLBACK(coordinate_fetch), circle[2]);
    g_signal_connect             (fcircle3, "clicked", G_CALLBACK(coordinate_fetch), circle[3]);
    g_signal_connect             (bcircle1, "clicked", G_CALLBACK(coordinate_fetch), circle[4]);
    g_signal_connect             (bcircle2, "clicked", G_CALLBACK(coordinate_fetch), circle[5]);
    g_signal_connect             (ftube, "clicked", G_CALLBACK(coordinate_fetch), circle[6]);
    g_signal_connect             (lrunway, "clicked", G_CALLBACK(coordinate_fetch), circle[7]);
    g_signal_connect             (rrunway, "clicked", G_CALLBACK(coordinate_fetch), circle[8]);
    g_signal_connect             (btube, "clicked", G_CALLBACK(coordinate_fetch), circle[9]);
    g_signal_connect             (platform1, "clicked", G_CALLBACK(coordinate_fetch2), circle[10]);
    g_signal_connect             (platform2, "clicked", G_CALLBACK(coordinate_fetch2), circle[11]);
    g_signal_connect             (platform3, "clicked", G_CALLBACK(coordinate_fetch2), circle[12]);
    g_signal_connect             (platform4, "clicked", G_CALLBACK(coordinate_fetch2), circle[13]);
    g_signal_connect             (platform5, "clicked", G_CALLBACK(coordinate_fetch2), circle[14]);
    g_signal_connect             (platform1, "clicked", G_CALLBACK(updateAngle), anglescale);
    g_signal_connect             (platform2, "clicked", G_CALLBACK(updateAngle), anglescale);
    g_signal_connect             (platform3, "clicked", G_CALLBACK(updateAngle), anglescale);
    g_signal_connect             (platform4, "clicked", G_CALLBACK(updateAngle), anglescale);
    g_signal_connect             (platform5, "clicked", G_CALLBACK(updateAngle), anglescale);
    g_signal_connect             (anglescale,"value-changed", G_CALLBACK(value_changed), angle);
    g_signal_connect             (anglescale2,"value-changed", G_CALLBACK(value_changed2), angle2);
    g_signal_connect_swapped     (shoot, "clicked", G_CALLBACK(g_print), "001\n");
    g_signal_connect_swapped     (closewindow, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    g_signal_connect             (anglescale,"value-changed", G_CALLBACK(update_status1), status);

    /*Attach to other grid*/
    /*gtk_grid_attach (~~~, NAME, column, row, width, height)*/
    gtk_grid_attach             (GTK_GRID(grid2), statusframe , 0, 0, 24, 2 );
    gtk_grid_attach             (GTK_GRID(grid2), hframe , 0, 2, 12, 6 );
    gtk_grid_attach             (GTK_GRID(grid2), tdframe , 0, 9, 12, 6 );
    gtk_grid_attach             (GTK_GRID(grid2), anglescale , 0, 8, 12, 1 );
    gtk_grid_attach             (GTK_GRID(grid2), anglescale2 , 12, 9, 1, 6 );
    gtk_grid_attach             (GTK_GRID(grid2), angleframe , 12, 2, 3, 1);
    gtk_grid_attach             (GTK_GRID(grid2), angleframe2 , 12, 3, 3, 1);
    gtk_grid_attach             (GTK_GRID(grid2), shoot , 15, 2, 9, 2);
    gtk_grid_attach             (GTK_GRID(grid2), closewindow , 21, 14, 3, 1);

    //CSS Styling Section
    GtkStyleContext *context;
    GtkCssProvider *provider = gtk_css_provider_new ();
    gtk_css_provider_load_from_path (provider,"gtk-widgets.css", NULL);

    context = gtk_widget_get_style_context(fcircle1);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"circularbuttons");

    context = gtk_widget_get_style_context(fcircle2);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"circularbuttons");

    context = gtk_widget_get_style_context(fcircle3);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"circularbuttons");

    context = gtk_widget_get_style_context(bcircle1);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"circularbuttons");

    context = gtk_widget_get_style_context(bcircle2);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"circularbuttons");

    context = gtk_widget_get_style_context(ftube);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"tubes");

    context = gtk_widget_get_style_context(btube);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"tubes");

    context = gtk_widget_get_style_context(grid);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"grid");

    context = gtk_widget_get_style_context(lrunway);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"runway");

    context = gtk_widget_get_style_context(rrunway);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"runway");

    context = gtk_widget_get_style_context(platform1);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"platform");

    context = gtk_widget_get_style_context(platform2);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"platform");

    context = gtk_widget_get_style_context(platform3);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"platform");

    context = gtk_widget_get_style_context(platform4);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"platform");

    context = gtk_widget_get_style_context(platform5);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"platform");

    context = gtk_widget_get_style_context(status);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"status");

    context = gtk_widget_get_style_context(angle);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"status");

    context = gtk_widget_get_style_context(angle2);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"status");

    context = gtk_widget_get_style_context(grid2);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"grid2");

    context = gtk_widget_get_style_context(closewindow);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"shoot");

    context = gtk_widget_get_style_context(anglescale);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"sliders");

    context = gtk_widget_get_style_context(anglescale2);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"sliders");

    context = gtk_widget_get_style_context(shoot);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_class(context,"shoot");

    //GtkWidget *image = gtk_image_new_from_file ("shoot.png"); get Takashi to launch this on Linux 2
    //gtk_button_set_image (GTK_BUTTON (shoot), image);

    gtk_widget_show_all         (window);
}

