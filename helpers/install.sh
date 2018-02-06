#!/bin/bash

service apache2 start;
if [ ! -d web ] && [ -f profile.make.yml ]; then
    drush make profile.make.yml web -y \
    && chown -R www-data:www-data /var/www/html/web \
    && ln -s /var/www/html/pssbl /var/www/html/web/profiles/pssbl \
    && cp /var/www/html/helpers/0000-site.conf /etc/apache2/sites-available/ \
    && a2ensite 0000-site;
    service apache2 restart;
    cd /var/www/html/web;
    drush site-install pssbl --db-url=mysql://drupal:drupal@mysql:3306/drupal --account-name=admin --account-pass=admin -y \
    && chown -R www-data:www-data /var/www/html/web \
    && echo "include_once '/var/www/html/web/sites/all/modules/domain/settings.inc';" >> /var/www/html/web/sites/default/settings.php;
fi;
tail -f /dev/null;
