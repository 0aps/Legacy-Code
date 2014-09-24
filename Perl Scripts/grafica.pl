use Tk;
$ventana = MainWindow->new(-cursor => "crosshair",-background=>"black"); #Primero creamos lo necesario
$ventana->geometry("400x400+400+400"); #Declaramos el tamaño de la ventana
$ventana->title("Formulario"); #Titulo de la ventana
$ventana->resizable(0,0); #Con esto podras hacer que la ventana sea imposible de ajustar
$ventana->Label(-text => "Llena los datos necesarios",-background=>"black",-foreground=>"red")->pack(); #Aca ponemos el texto hola mundo
$ventana->Entry(-background=>"black",-foreground=>"red")->pack();
$ventana->Label(-background=>"black")->pack(); # Espacio
$ventana->Label(-background=>"black")->pack(); # Espacio
MainLoop;