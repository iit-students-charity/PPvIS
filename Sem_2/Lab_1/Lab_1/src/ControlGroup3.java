import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Group;


//Control group #3
public class ControlGroup3
{
	Shell parentShell;
	Group group;
	Text text;
	Button button;
	int radiobuttonsQuantity = 3;
	Group radiobuttonsGroup;
	Button[] radiobuttons;
	
	ControlGroup3(Shell otherShell)
	{
		parentShell = otherShell;
		
		group = new Group(parentShell, SWT.NONE);
		group.setLayout(new RowLayout(SWT.VERTICAL));
		
		text = new Text(group, SWT.NULL);
		text.setLayoutData(new RowData(182, 50));
		
		button = new Button(group, SWT.PUSH);
		button.setText("Click Me");
		button.setLayoutData(new RowData(190, 50));
		button.addSelectionListener(new SelectionListener()
		{
			@Override
			public void widgetSelected(SelectionEvent event) 
			{
				boolean isThisFound = false;
			    for (int currRadiobuttonNumb = 0; currRadiobuttonNumb < radiobuttonsQuantity; currRadiobuttonNumb++)
			    {
			    	if (text.getText().equals(radiobuttons[currRadiobuttonNumb].getText()))
			    	{
			    		radiobuttons[currRadiobuttonNumb].setSelection(true);
			    		isThisFound = true;
			    	}
			    	else
			    	{
			    		radiobuttons[currRadiobuttonNumb].setSelection(false);
			    	}
			    }
			    if (!isThisFound)
			    {
			    	new ErrorWindow(parentShell).run();
			    }
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
		
		radiobuttonsGroup = new Group(group, SWT.NONE);
		radiobuttonsGroup.setLayout(new FillLayout(SWT.VERTICAL));
		radiobuttonsGroup.setText("Choices");
		radiobuttons = new Button[radiobuttonsQuantity];
		for (int currRadiobuttonNumb = 0; currRadiobuttonNumb < radiobuttonsQuantity; currRadiobuttonNumb++)
		{
			radiobuttons[currRadiobuttonNumb] = new Button(radiobuttonsGroup, SWT.RADIO);
			radiobuttons[currRadiobuttonNumb].setSelection(false);
			radiobuttons[currRadiobuttonNumb].setText("RB " + Integer.toString(currRadiobuttonNumb + 1));
		}
	}
}
