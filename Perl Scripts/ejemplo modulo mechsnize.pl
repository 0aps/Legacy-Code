#!/usr/bin/perl
use WWW::Mechanize;
my $m = WWW::Mechanize->new();

$url = 'http://www.portalhacker.net/index.php/topic,126238.msg621878/topicseen.html';
$m->get($url);
$m->form_name('postmodify');
$m->field('message', 'Cuando no!');
$response = $m->submit();
print $response;
