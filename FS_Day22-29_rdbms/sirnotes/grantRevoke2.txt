create user subbu identified by 'kmit';
grant select on test.emp to subbu;

select distinct user from mysql.user where user <> '' order by user;

// Login to mysql with new user name - subbu

1) To login set the mysql path to the environment path settings
D:\MySQL\MySQL Server 8.0\bin;

2) Open a new command prompt with administrator rights

3) Run the following command to login as subbu

mysql -u subbu -p

When prompted for password enter
kmit

Execute the following commands to check granted permissions and error for what is not granted

select ename from emp;

select * from dept;

update emp set ename='Raj' where ename='SMITH';
-----------------------------------------------------------
grant select on dept to subbu;

grant update on test.emp to subbu;
update emp set ename='Raj';
select ename from emp;
----------------------------------------------------------
GRANT ALL PRIVILEGES ON test.emp TO subbu;

select ename from emp;
update emp set ename='ramesh' where ename='CLARK';
select ename from emp;
delete from emp where deptno = 20;
----------------------------------------------------------
revoke update on test.emp from subbu;
update emp set ename='Raj';

revoke select on test.emp from subbu;
select ename from emp;
----------------------------------------------------------
revoke ALL ON test.emp from subbu;

select ename from emp;
update emp set ename='ram' where ename='ALLEN';
drop table emp;
-----------------------------------------------------
SHOW GRANTS FOR subbu;

drop user 'subbu';
-----------------------------------------------------

grant execute on procedure test.empCount to subbu;
grant execute on function test.getSalGrade to subbu;

revoke execute on procedure test.empCount from subbu;
revoke execute on function test.getSalGrade from subbu;
--------------------------------------------------------