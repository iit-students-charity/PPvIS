package lab_2.controls;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;

public class SearchDialogControl {
	Display display;
	Shell shell;

	public SearchDialogControl(Display d, Shell s)
	{
		display = d;
		shell = s;
	}
	
	public void run() {
	    shell.open();
	    while (!shell.isDisposed()) {
	      if (!display.readAndDispatch()) {
	        display.sleep();
	      }
	    }
	}
}
