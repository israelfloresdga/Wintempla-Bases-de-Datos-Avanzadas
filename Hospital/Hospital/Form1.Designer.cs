namespace Hospital
{
	partial class Form1
	{
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		/// <param name="disposing">true si los recursos administrados se deben eliminar; false en caso contrario.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Código generado por el Diseñador de Windows Forms

		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		private void InitializeComponent()
		{
			this.label_patient = new System.Windows.Forms.Label();
			this.cbPatient = new System.Windows.Forms.ComboBox();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.radioButton_Oracle = new System.Windows.Forms.RadioButton();
			this.radioButton_MS = new System.Windows.Forms.RadioButton();
			this.button_Generate = new System.Windows.Forms.Button();
			this.groupBox1.SuspendLayout();
			this.SuspendLayout();
			// 
			// label_patient
			// 
			this.label_patient.AutoSize = true;
			this.label_patient.Location = new System.Drawing.Point(12, 16);
			this.label_patient.Name = "label_patient";
			this.label_patient.Size = new System.Drawing.Size(40, 13);
			this.label_patient.TabIndex = 0;
			this.label_patient.Text = "Patient";
			this.label_patient.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// cbPatient
			// 
			this.cbPatient.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbPatient.ForeColor = System.Drawing.Color.SteelBlue;
			this.cbPatient.FormattingEnabled = true;
			this.cbPatient.Location = new System.Drawing.Point(58, 13);
			this.cbPatient.Name = "cbPatient";
			this.cbPatient.Size = new System.Drawing.Size(258, 21);
			this.cbPatient.TabIndex = 1;
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.radioButton_Oracle);
			this.groupBox1.Controls.Add(this.radioButton_MS);
			this.groupBox1.Location = new System.Drawing.Point(15, 52);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(301, 73);
			this.groupBox1.TabIndex = 2;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "DataBase";
			// 
			// radioButton_Oracle
			// 
			this.radioButton_Oracle.AutoSize = true;
			this.radioButton_Oracle.Location = new System.Drawing.Point(6, 42);
			this.radioButton_Oracle.Name = "radioButton_Oracle";
			this.radioButton_Oracle.Size = new System.Drawing.Size(146, 17);
			this.radioButton_Oracle.TabIndex = 1;
			this.radioButton_Oracle.TabStop = true;
			this.radioButton_Oracle.Text = "Oracle Database XE 11.2";
			this.radioButton_Oracle.UseVisualStyleBackColor = true;
			this.radioButton_Oracle.Click += new System.EventHandler(this.radioButton_Oracle_Click);
			// 
			// radioButton_MS
			// 
			this.radioButton_MS.AutoSize = true;
			this.radioButton_MS.Location = new System.Drawing.Point(6, 19);
			this.radioButton_MS.Name = "radioButton_MS";
			this.radioButton_MS.Size = new System.Drawing.Size(153, 17);
			this.radioButton_MS.TabIndex = 0;
			this.radioButton_MS.TabStop = true;
			this.radioButton_MS.Text = "Microsoft SQL Server 2008";
			this.radioButton_MS.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			this.radioButton_MS.UseVisualStyleBackColor = true;
			this.radioButton_MS.Click += new System.EventHandler(this.radioButton_MS_Click);
			// 
			// button_Generate
			// 
			this.button_Generate.Location = new System.Drawing.Point(15, 134);
			this.button_Generate.Name = "button_Generate";
			this.button_Generate.Size = new System.Drawing.Size(301, 24);
			this.button_Generate.TabIndex = 3;
			this.button_Generate.Text = "Generate patient_visit_id";
			this.button_Generate.UseVisualStyleBackColor = true;
			this.button_Generate.Click += new System.EventHandler(this.button_Generate_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(328, 170);
			this.Controls.Add(this.button_Generate);
			this.Controls.Add(this.groupBox1);
			this.Controls.Add(this.cbPatient);
			this.Controls.Add(this.label_patient);
			this.Name = "Form1";
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label_patient;
		private System.Windows.Forms.ComboBox cbPatient;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.RadioButton radioButton_Oracle;
		private System.Windows.Forms.RadioButton radioButton_MS;
		private System.Windows.Forms.Button button_Generate;
	}
}

