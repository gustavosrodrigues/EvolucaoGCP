; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "GCP"
#define MyAppVersion "3.7"
#define MyAppPublisher "UNIPAMPA"
#define MyAppURL "http://www.unipampa.edu.br/"
#define MyAppExeName "GCPLauncher.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{F8A13750-0F15-41C4-A9CF-B063A638EA36}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputDir=E:\GCP 3.7 BCB 2010\GCP 3.7 BCB 2010\Release GCP 3.7\Setup
OutputBaseFilename=Setup_GCP_3.7
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "portuguese"; MessagesFile: "compiler:Languages\Portuguese.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "E:\GCP 3.7 BCB 2010\GCP 3.7 BCB 2010\Release GCP 3.7\GCPLauncher.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "E:\GCP 3.7 BCB 2010\GCP 3.7 BCB 2010\Release GCP 3.7\GCPLauncher.ini"; DestDir: "{app}"; Flags: ignoreversion
Source: "E:\GCP 3.7 BCB 2010\GCP 3.7 BCB 2010\Release GCP 3.7\3.7\*"; DestDir: "{app}\3.7"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "E:\GCP 3.7 BCB 2010\GCP 3.7 BCB 2010\Release GCP 3.7\regras\*"; DestDir: "{app}\regras"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\3.7\GCP.exe"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\3.7\GCP.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

