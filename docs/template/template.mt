? my ($title, $sections) = @_;
<!DOCTYPE html>
<!--
  TechFUN HTML5 slide template

  Authors: Kodama Shindo(@kodam)

  Using: Google HTML5 slides template(https://code.google.com/p/html5slides/)
-->
<html>
  <head>
    <title><?= $title ?></title>
    <meta charset="utf-8" />
    <script src="../template/files/slides.js"></script>
    <style>
.slides article em {
    color: red;
    font-style: normal;
}
    </style>
  </head>
  <body style="display: none">
    <section class='slides layout-regular template-default'>
? for my $section (@$sections) {
      <article>
<?= Text::MicroTemplate::encoded_string($section) ?>      </article>
? }
    </section>
  </body>
</html>
