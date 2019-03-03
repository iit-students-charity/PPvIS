import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;

public class ControlGroup4
{
	Group group;
	Text text;
	Button button;
	int checkboxesQuantity = 3;
	Group checkboxesGroup;
	Button[] checkboxes;
	
	ControlGroup4(Shell parentShell)
	{
		
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
			    for (int currRadiobuttonNumb = 0; currRadiobuttonNumb < checkboxesQuantity; currRadiobuttonNumb++)
			    {
			    	if (text.getText().equals(checkboxes[currRadiobuttonNumb].getText()))
			    	{
			    		checkboxes[currRadiobuttonNumb].setSelection(!checkboxes[currRadiobuttonNumb].getSelection());
			    		isThisFound = true;
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
		
		//Radiobutton grouping
		checkboxesGroup = new Group(group, SWT.NONE);
		checkboxesGroup.setLayout(new FillLayout(SWT.VERTICAL));
		checkboxesGroup.setText("Choices");
		
		//Procedural generatinon of radiobuttons
		checkboxes = new Button[checkboxesQuantity];
		
		for (int currRadiobuttonNumb = 0; currRadiobuttonNumb < checkboxesQuantity; currRadiobuttonNumb++)
		{
			checkboxes[currRadiobuttonNumb] = new Button(checkboxesGroup, SWT.CHECK);
			checkboxes[currRadiobuttonNumb].setSelection(false);
			checkboxes[currRadiobuttonNumb].setText("RB " + Integer.toString(currRadiobuttonNumb + 1));
		}
	}
}

