package lab_2.controls;
import lab_2.gui.SearchDialog;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;

public class GUIControl {
	Display display;
	Shell shell;

	public GUIControl(Display d, Shell s)
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
		display.dispose();
	}
	
	public void findButtonAction() {
		new SearchDialog(shell);
	}
	
	public void removeButtonAction() {
		
	}
}
