package lab_2.gui;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import lab_2.controls.GUIControl;



public class GUI {
	Display display;
	Shell shell;
	Table table;
	TableColumn column;
	String[] titles = { "ФИО спортсена", "Состав (если имеется)", "Позиция",
			"Титулы", "Виды спорта", "Разряд"};
	public GUIControl guiControl;
	
	public GUI(){
		display = new Display();
		shell = new Shell();
		guiControl = new GUIControl(display, shell);
		initUI();
	}
	
	public void initUI() {
		shell.setSize(800, 600);
		shell.setText("Lab 2");
		GridLayout shellLayout = new GridLayout();
		shellLayout.numColumns = 1;
		shell.setLayout(shellLayout);
		
		table = new Table(shell, SWT.BORDER | SWT.FULL_SELECTION);
		for (int currTitle = 0; currTitle < titles.length; currTitle++)
		{
			column = new TableColumn(table, SWT.LEFT);
			column.setWidth(93);
		    column.setText(titles[currTitle]);
		}
		table.setHeaderVisible(true);
		table.setLinesVisible(true);
		GridData tableData = new GridData();
		tableData.horizontalAlignment = GridData.FILL;
		tableData.grabExcessHorizontalSpace = true;
		tableData.verticalAlignment = GridData.FILL;
		tableData.grabExcessVerticalSpace = true;
		table.setLayoutData(tableData);
		
		Group buttonGroup = new Group(shell, SWT.NONE);
		buttonGroup.setLayout(new FillLayout(SWT.HORIZONTAL));
		GridData buttonGroupData = new GridData();
		buttonGroupData.horizontalAlignment = GridData.FILL;
		buttonGroupData.grabExcessHorizontalSpace = true;
		buttonGroup.setLayoutData(buttonGroupData);
		
		Button findButton = new Button(buttonGroup, SWT.PUSH);
		findButton.setText("Найти");
		findButton.addSelectionListener(new SelectionListener()
		{
			@Override
			public void widgetSelected(SelectionEvent event) 
			{
				guiControl.findButtonAction();
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
		
		Button removeButton = new Button(buttonGroup, SWT.PUSH);
		removeButton.setText("Удалить");
		removeButton.addSelectionListener(new SelectionListener()
		{
			@Override
			public void widgetSelected(SelectionEvent event) 
			{
				guiControl.removeButtonAction();
			}
			    	
			@Override
			public void widgetDefaultSelected(SelectionEvent event) {}
		});
		
	}
}
