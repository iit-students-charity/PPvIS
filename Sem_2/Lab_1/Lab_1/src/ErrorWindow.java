import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Dialog;
import org.eclipse.swt.widgets.Label;


//Dialog window that reports an error
public class ErrorWindow extends Dialog
{
	Display display;
	Shell shell;
	
	ErrorWindow(Shell parentShell)
	{
		super(parentShell);
		
		display = parentShell.getDisplay();		
		shell = new Shell(parentShell, SWT.APPLICATION_MODAL| SWT.DIALOG_TRIM);
		shell.setSize(320, 240);
		shell.setText("Error!");
		
		//Error text
		new Label(shell, SWT.NONE).setText("Enter a correct request!");
	}
	
	//Run the window
	public void run()
	{
		shell.open();
		
		 while (!shell.isDisposed())
		 {
		      if (!display.readAndDispatch())
		      {
		        display.sleep();
		      }
		 }
	}
}
