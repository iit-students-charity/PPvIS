import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.layout.FillLayout;


public class MainWindow
{
	Display display;
	Shell shell;
	RunningString runningString;
	
	MainWindow()
	{
		display = new Display();
		shell = new Shell();
		runningString = new RunningString(shell);
		new Thread(new Runnable()
		{
			public void run()
		    {
				while (true)
				{
					Display.getDefault().syncExec(new Runnable()
		            {
						public void run() 
						{
							runningString.runString();
						}
		            });
				}
		     }
		 }).start();
		shell.setSize(1024, 420);
		shell.setText("");
		shell.setLayout(new FillLayout(SWT.HORIZONTAL));
		new ControlGroup1(shell);
		new ControlGroup2(shell);
		new ControlGroup3(shell);
		new ControlGroup4(shell);
		new ControlGroup5(shell);
	}
	
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
		display.dispose();
	}
	
	public static void main(String[] args)
	{
		new MainWindow().run();
	}
}


class RunningString
{
	final long runningStringSpeed = 20; //in ms
	final int runningStringMaxSpaces = 250;
	final String title = "Lab 1";
	
	Shell parentShell;
	String boof;
	long prevTime;
	
	RunningString(Shell otherShell)
	{
		super();
		parentShell = otherShell;
		boof = new String("");
		prevTime = System.currentTimeMillis();
	}
	
	public void runString()
	{
			if (System.currentTimeMillis() - prevTime > runningStringSpeed)
			{
				prevTime = System.currentTimeMillis();
				parentShell.setText(boof + title);
				boof += " ";
				if (boof.length() == runningStringMaxSpaces)
				{
					boof = "";
				}
			}
	}
}